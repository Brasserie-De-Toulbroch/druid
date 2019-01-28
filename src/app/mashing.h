#pragma once

#include <QGroupBox>

#include "ui_mashing.h"

class DruidMashing : public QGroupBox, public Ui::DruidMashing {
  Q_OBJECT

 public:
  DruidMashing();
};
