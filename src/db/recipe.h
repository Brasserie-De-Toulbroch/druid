#pragma once

#include <QString>

class DruidRecipe {
 public:
  DruidRecipe() = default;

  bool is_valid() const;

  void setTitle(const QString &title);
  QString title() const;

  void setNotes(const QString &notes);
  QString notes() const;

 private:
  QString _title;
  QString _notes;
};
