#include <iostream>

#include "db.h"

DruidDb::DruidDb(const QString &filename) : _table("recipes") {
  open(filename);
}

DruidDb::~DruidDb() { close(); }

bool DruidDb::open(const QString &filename) {
  if (_db) {
    close();
  }

  return sqlite3_open(filename.toStdString().c_str(), &_db);
}

DruidRecipe DruidDb::recipe(const QString &title) const {
  DruidRecipe recipe;

  const QString sql = QString("SELECT title, notes FROM %1 where title = '%2'")
                          .arg(_table, title);

  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(_db, sql.toStdString().c_str(), -1, &stmt, NULL) !=
      SQLITE_OK) {
    std::cerr << "ERROR: " << sqlite3_errmsg(_db) << std::endl;
    sqlite3_finalize(stmt);
    return recipe;
  }

  int ret_code = 0;
  while ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW) {
    // title
    const QString title((char *)sqlite3_column_text(stmt, 0));
    recipe.set_title(title);

    // notes
    const QString notes((char *)sqlite3_column_text(stmt, 1));
    recipe.set_notes(notes);
  }

  if (ret_code != SQLITE_DONE) {
    std::cerr << "ERROR: " << sqlite3_errmsg(_db) << std::endl;
  }

  sqlite3_finalize(stmt);

  for (const auto malt : malts(recipe.title())) {
    recipe.add_malt(malt);
  }

  return recipe;
}

QList<DruidRecipe> DruidDb::recipes() const {
  QList<DruidRecipe> recipes;

  const QString sql =
      QString(
          "SELECT title, notes, final_vol, mashing_water_vol, "
          "mashing_wort_vol, mashing_temp, mashing_duration, yeast FROM %1")
          .arg(_table);

  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(_db, sql.toStdString().c_str(), -1, &stmt, NULL) !=
      SQLITE_OK) {
    std::cerr << "ERROR: " << sqlite3_errmsg(_db) << std::endl;
    sqlite3_finalize(stmt);
    return QList<DruidRecipe>();
  }

  int rc;
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    DruidRecipe recipe;

    const QString title((char *)sqlite3_column_text(stmt, 0));
    const QString notes((char *)sqlite3_column_text(stmt, 1));
    const int volume(sqlite3_column_int(stmt, 2));
    const int mash_water_vol(sqlite3_column_int(stmt, 3));
    const int mash_wort_vol(sqlite3_column_int(stmt, 4));
    const int mash_temp(sqlite3_column_int(stmt, 5));
    const int mash_duration(sqlite3_column_int(stmt, 6));
    const QString yeast((char *)sqlite3_column_text(stmt, 7));

    recipe.set_title(title);
    recipe.set_notes(notes);
    recipe.set_volume(volume);
    recipe.set_mashing_temperature(mash_temp);
    recipe.set_mashing_wort_volume(mash_wort_vol);
    recipe.set_mashing_water_volume(mash_water_vol);
    recipe.set_mashing_duration(mash_duration);
    recipe.set_yeast(yeast);

    for (const auto malt : malts(recipe.title())) {
      recipe.add_malt(malt);
    }

    recipes.append(recipe);
  }

  return recipes;
}

bool DruidDb::recipe_exists(const QString &title) const {
  bool exist = false;

  const QString sql =
      QString("SELECT title FROM %1 where title = '%2'").arg(_table, title);

  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(_db, sql.toStdString().c_str(), -1, &stmt, NULL) !=
      SQLITE_OK) {
    std::cerr << "ERROR: " << sqlite3_errmsg(_db) << std::endl;
    sqlite3_finalize(stmt);
    return exist;
  }

  int ret_code = 0;
  int column = 0;
  while ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW) {
    // title
    if (column == 0) {
      exist = true;
    }
  }

  if (ret_code != SQLITE_DONE) {
    std::cerr << "ERROR: " << sqlite3_errmsg(_db) << std::endl;
  }

  sqlite3_finalize(stmt);

  return exist;
}

bool DruidDb::recipe_add(const DruidRecipe &recipe) const {
  const QString sql =
      QString(
          "INSERT INTO %1(title, notes, final_vol, mashing_water_vol, "
          "mashing_wort_vol, mashing_temp, mashing_duration, yeast) "
          "VALUES('%2', '%3', %4, %5, %6, %7, %8, '%9')")
          .arg(_table, recipe.title(), recipe.notes(),
               QString::number(recipe.volume()),
               QString::number(recipe.mashing_water_volume()),
               QString::number(recipe.mashing_wort_volume()),
               QString::number(recipe.mashing_temperature()),
               QString::number(recipe.mashing_duration()), recipe.yeast());
  exec(sql);

  const int id = recipe_id(recipe.title());
  for (const auto malt : recipe.malts()) {
    malt_add(id, malt);
  }
}

void DruidDb::malt_add(const int recipe_id, const DruidMalt &malt) const {
  if (!malt.is_valid()) {
    return;
  }

  const QString sql =
      QString(
          "INSERT INTO malts(recipe_id, name, ebc, weight) VALUES(%1, '%2', "
          "%3, %4)")
          .arg(QString::number(recipe_id), malt.name(),
               QString::number(malt.ebc()), QString::number(malt.weight()));
  exec(sql);
}

bool DruidDb::recipe_update(const DruidRecipe &recipe) const {
  QString sql =
      QString(
          "UPDATE %1 SET notes='%2', final_vol=%3, mashing_water_vol=%4, "
          "mashing_wort_vol=%5, mashing_temp=%6, mashing_duration=%7, "
          "yeast='%8' WHERE "
          "title='%9'")
          .arg(_table, recipe.notes(), QString::number(recipe.volume()),
               QString::number(recipe.mashing_water_volume()),
               QString::number(recipe.mashing_wort_volume()),
               QString::number(recipe.mashing_temperature()),
               QString::number(recipe.mashing_duration()), recipe.yeast(),
               recipe.title());
  exec(sql);

  sql = QString("DELETE FROM malts");
  exec(sql);

  const int id = recipe_id(recipe.title());
  for (const auto malt : recipe.malts()) {
    malt_add(id, malt);
  }
}

bool DruidDb::is_ready() const {
  bool ready = false;

  if (_db) {
    const QString sql = QString(
                            "SELECT name FROM sqlite_master WHERE "
                            "type='table' AND name='%1'")
                            .arg(_table);

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(_db, sql.toStdString().c_str(), -1, &stmt, NULL) !=
        SQLITE_OK) {
      std::cerr << "ERROR: " << sqlite3_errmsg(_db) << std::endl;
      sqlite3_finalize(stmt);
      return false;
    }

    int ret_code = 0;
    while ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW) {
      const QString result((char *)sqlite3_column_text(stmt, 0));
      if (result.compare(_table) == 0) {
        ready = true;
      }
    }

    if (ret_code != SQLITE_DONE) {
      std::cerr << "ERROR: " << sqlite3_errmsg(_db) << std::endl;
    }

    sqlite3_finalize(stmt);
  }

  return ready;
}

bool DruidDb::close() {
  if (_db) {
    sqlite3_close(_db);
    _db = nullptr;
  }
}

int DruidDb::recipe_id(const QString &title) const {
  int recipe_id = -1;

  const QString sql =
      QString("SELECT id FROM %1 where title = '%2'").arg(_table, title);

  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(_db, sql.toStdString().c_str(), -1, &stmt, NULL) !=
      SQLITE_OK) {
    std::cerr << "ERROR: " << sqlite3_errmsg(_db) << std::endl;
    sqlite3_finalize(stmt);
    return recipe_id;
  }

  int ret_code = 0;
  while ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW) {
    // id
    recipe_id = sqlite3_column_int(stmt, 0);
  }

  if (ret_code != SQLITE_DONE) {
    std::cerr << "ERROR: " << sqlite3_errmsg(_db) << std::endl;
  }

  sqlite3_finalize(stmt);

  return recipe_id;
}

QList<DruidMalt> DruidDb::malts(const QString &title) const {
  QList<DruidMalt> malts;

  const QString sql =
      QString("SELECT name, ebc, weight FROM malts where recipe_id = %2")
          .arg(QString::number(recipe_id(title)));

  sqlite3_stmt *stmt;
  if (sqlite3_prepare_v2(_db, sql.toStdString().c_str(), -1, &stmt, NULL) !=
      SQLITE_OK) {
    std::cerr << "ERROR DruidDb::malts prepare: " << sqlite3_errmsg(_db)
              << std::endl;
    sqlite3_finalize(stmt);
    return QList<DruidMalt>();
  }

  int ret_code = 0;
  while ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW) {
    // add malt
    DruidMalt malt;
    malt.set_name((char *)sqlite3_column_text(stmt, 0));
    malt.set_ebc(sqlite3_column_int(stmt, 1));
    malt.set_weight(sqlite3_column_int(stmt, 2));

    if (malt.is_valid()) {
      malts << malt;
    }
  }

  if (ret_code != SQLITE_DONE) {
    std::cerr << "ERROR DruidDb::malts step: " << sqlite3_errmsg(_db)
              << std::endl;
  }

  sqlite3_finalize(stmt);

  return malts;
}

bool DruidDb::exec(const QString &sql) const {
  return sqlite3_exec(_db, sql.toStdString().c_str(), 0, 0, 0);
}
