#pragma once

#include <QGroupBox>
#include <QLineEdit>

#include "ui_fermentation.h"

class DruidFermentation : public QGroupBox, public Ui::DruidFermentation {
  Q_OBJECT

 public:
  DruidFermentation();

  void set_yeast(const QString &yeast);
  QString yeast() const;

 private:
  QLineEdit _yeast;
};
