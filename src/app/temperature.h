#pragma once

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QGroupBox>
#include <QPointF>
#include <QVector>

#include "ds18b20.h"
#include "ui_temperature.h"

class DruidTemperature : public QGroupBox, public Ui::DruidTemperature {
  Q_OBJECT

 public:
  DruidTemperature();
  void set_sensor(const bard::DS18B20 *sensor);

 private:
  void start();
  void stop();
  void update();

  QwtPlot _plot;
  QwtPlotCurve _curve;
  bool _timer_stop = false;
  QVector<QPointF> _values;
  const bard::DS18B20 *_sensor = nullptr;
};
