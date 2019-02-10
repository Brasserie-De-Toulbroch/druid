#pragma once

#include <QGroupBox>
#include <QPointF>
#include <QVector>
#include <QwtPlot>
#include <QwtPlotCurve>

#include "ui_temperature.h"

class DruidTemperature : public QGroupBox, public Ui::DruidTemperature {
  Q_OBJECT

 public:
  DruidTemperature();

 private:
  void start();
  void stop();
  void update();

  QwtPlot _plot;
  QwtPlotCurve _curve;
  bool _timer_stop = false;
  QVector<QPointF> _values;
};
