#pragma once

#include <QGroupBox>
#include <QLineEdit>

#include "db/malt.h"
#include "ui_mashing.h"

class DruidMashing : public QGroupBox, public Ui::DruidMashing {
  Q_OBJECT

 public:
  DruidMashing();

  QList<DruidMalt> malts() const;
  void set_malts(const QList<DruidMalt> &malts);

  void set_temperature(int temperature);
  int temperature() const;

  void set_water_volume(int volume);
  int water_volume() const;

  void set_wort_volume(int volume);
  int wort_volume() const;

  void set_duration(int duration);
  int duration() const;

 private:
  QList<QLineEdit *> _malts;
  QList<QLineEdit *> _ebc;
  QList<QLineEdit *> _weight;
  QLineEdit _tmp;
  QLineEdit _vol_water;
  QLineEdit _vol_wort;
  QLineEdit _duration;
};
