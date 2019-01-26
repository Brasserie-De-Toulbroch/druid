#pragma once

#include <sqlite3.h>

#include <QString>

class DruidDb {
 public:
  DruidDb(const QString &filename);
  ~DruidDb();

  bool open(const QString &filename);
  bool is_ready() const;
  bool close();

  bool exec(const QString &sql) const;

 private:
  sqlite3 *_db = nullptr;
  QString _table;
};
