#pragma once

#include <QString>

class DruidRecipe {
 public:
  DruidRecipe() = default;

  bool is_valid() const;

  void setTitle(const QString &title);
  QString title() const;

 private:
  QString _title;
};
