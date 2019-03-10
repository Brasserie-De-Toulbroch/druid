#include <QColor>
#include <QPen>
#include <QTimer>

#include <temperature.h>

DruidTemperature::DruidTemperature() {
  setupUi(this);

  _plot.setAxisScale(QwtPlot::yLeft, 0.0, 100.0);
  QPen pen;
  pen.setWidth(3);
  pen.setColor(QColor(23, 154, 224));
  _curve.setPen(pen);
  _curve.setRenderHint(QwtPlotItem::RenderAntialiased, true);
  _curve.attach(&_plot);
  _top_layout->addWidget(&_plot);

  connect(_start, &QPushButton::clicked, this, &DruidTemperature::start);
  connect(_stop, &QPushButton::clicked, this, &DruidTemperature::stop);
}

void DruidTemperature::start() {
  QTimer::singleShot(1000, this, &DruidTemperature::update);
  _timer_stop = false;
}

void DruidTemperature::update() {
  if (!_timer_stop) {
    QTimer::singleShot(1000, this, &DruidTemperature::update);

    float temperature = 0.0;
    if (_sensor) {
      temperature = _sensor->temperature();
    }
    _lcd->display(QString::number(temperature));

    const QPointF value(_values.size(), temperature);
    _values.push_back(value);
    _curve.setSamples(_values);
    _plot.replot();
  }
}

void DruidTemperature::stop() {
  _timer_stop = true;
  _values.clear();
  _lcd->display(QString::number(0));
  _curve.setSamples(_values);
  _plot.replot();
}

void DruidTemperature::set_sensor(const bard::DS18B20 *sensor) {
  _sensor = sensor;
}
