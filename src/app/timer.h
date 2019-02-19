#pragma once

#include <QGroupBox>
#include <QTimer>

#include "ui_timer.h"

class DruidTimer : public QGroupBox, public Ui::DruidTimer {
  Q_OBJECT

 public:
  DruidTimer();

 private:
  void start();
  void stop();
  void update();

  static QString msecs_to_string(int millisecondes);

  QTimer _timer;
  bool _timer_stop = false;
  bool _red = false;
  QPalette _default_palette;
};
