#pragma once

#include <sqlite3.h>

#include <QString>

#include "recipe.h"

class DruidDb {
 public:
  DruidDb(const QString &filename);
  ~DruidDb();

  bool open(const QString &filename);
  bool is_ready() const;
  bool init() const;
  bool close();

  DruidRecipe recipe(const QString &title) const;
  bool add_recipe(const DruidRecipe &recipe) const;

  bool exec(const QString &sql) const;

 private:
  sqlite3 *_db = nullptr;
  QString _table;
};
