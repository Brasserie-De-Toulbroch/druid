#pragma once

#include <QList>
#include <QString>

#include "malt.h"

class DruidRecipe {
 public:
  DruidRecipe() = default;

  bool is_valid() const;

  void set_title(const QString &title);
  QString title() const;

  void set_notes(const QString &notes);
  QString notes() const;

  void add_malt(const DruidMalt &malt);
  QList<DruidMalt> malts() const;

 private:
  QString _title;
  QString _notes;
  QList<DruidMalt> _malts;
};
