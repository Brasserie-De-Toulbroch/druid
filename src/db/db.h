#pragma once

#include <sqlite3.h>

#include <QList>
#include <QString>

#include "recipe.h"

class DruidDb {
 public:
  DruidDb(const QString &filename);
  ~DruidDb();

  bool open(const QString &filename);
  bool is_ready() const;
  bool close();

  QList<DruidRecipe> recipes() const;
  DruidRecipe recipe(const QString &title) const;
  bool recipe_exists(const QString &title) const;
  bool recipe_add(const DruidRecipe &recipe) const;
  bool recipe_update(const DruidRecipe &recipe) const;

  bool exec(const QString &sql) const;

 private:
  void malt_add(int recipe_id, const DruidMalt &malt) const;
  int recipe_id(const QString &title) const;
  QList<DruidMalt> malts(const QString &title) const;

  sqlite3 *_db = nullptr;
  QString _table;
};
