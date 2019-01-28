#pragma once

#include <QGroupBox>

#include "ui_fermentation.h"

class DruidFermentation : public QGroupBox, public Ui::DruidFermentation {
  Q_OBJECT

 public:
  DruidFermentation();
};
