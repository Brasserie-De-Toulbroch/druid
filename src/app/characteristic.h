#pragma once

#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>

#include "ui_characteristic.h"

class DruidCharacteristic : public QGroupBox, public Ui::DruidCharacteristic {
  Q_OBJECT

 public:
  DruidCharacteristic();

  void set_ebc(float ebc);

  void set_volume(float volume);
  float volume() const;

 signals:
  void update_ebc();

 private:
  QLineEdit _ebc;
  QPushButton _ebc_color;
  QLineEdit _volume;
};
