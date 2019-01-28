#pragma once

#include <QGroupBox>

#include "ui_boiling.h"

class DruidBoiling : public QGroupBox, public Ui::DruidBoiling {
  Q_OBJECT

 public:
  DruidBoiling();
};
