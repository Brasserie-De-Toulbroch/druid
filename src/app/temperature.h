#pragma once

#include <QGroupBox>

#include "ui_temperature.h"

class DruidTemperature : public QGroupBox, public Ui::DruidTemperature {
  Q_OBJECT

 public:
  DruidTemperature();

 private:
  // QLineSeries series;
  // QChart _chart;
};
