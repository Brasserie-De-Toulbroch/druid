#pragma once

#include <QPointer>
#include <QWidget>

#include "temperature.h"
#include "timer.h"
#include "ui_central_widget.h"
#include "volume.h"

class DruidCentralWidget : public QWidget, public Ui::DruidCentralWidget {
  Q_OBJECT

 public:
  DruidCentralWidget();

  DruidTemperature* temperature_widget();

 private:
  DruidTimer _timer;
  DruidVolume _volume;
  DruidTemperature _temperature;
};
