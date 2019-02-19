#include <iostream>

#include "central_widget.h"

DruidCentralWidget::DruidCentralWidget() {
  setupUi(this);

  _top_layout->addWidget(&_temperature);
  _bottom_layout->addWidget(&_timer);
  _bottom_layout->addWidget(&_volume);
}

DruidTemperature* DruidCentralWidget::temperature_widget() {
  return &_temperature;
}
