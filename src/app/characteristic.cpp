#include <QLabel>

#include <iostream>

#include "characteristic.h"
#include "utils/ebc_colors.h"

DruidCharacteristic::DruidCharacteristic() {
  setupUi(this);

  QGridLayout *grid_layout = (QGridLayout *)layout();
  grid_layout->addWidget(new QLabel("Final Volume"), 0, 0);
  grid_layout->addWidget(&_volume, 0, 1);

  grid_layout->addWidget(new QLabel("EBC"), 1, 0);
  grid_layout->addWidget(&_ebc, 1, 1);
  grid_layout->addWidget(&_ebc_color, 1, 2);

  connect(&_ebc_color, &QPushButton::clicked, this,
          &DruidCharacteristic::update_ebc);
}

void DruidCharacteristic::set_ebc(const float ebc) {
  _ebc.setText(QString::number(ebc));

  const QColor color = DruidUtils::to_color(ebc);

  const QString ss =
      QString("background-color: rgb(%1, %2, %3)")
          .arg(QString::number(color.red()), QString::number(color.green()),
               QString::number(color.blue()));
  _ebc_color.setStyleSheet(ss);

  QPalette pal = _ebc_color.palette();
  pal.setColor(QPalette::Button, QColor(color));
  _ebc_color.setAutoFillBackground(true);
  _ebc_color.setPalette(pal);
  _ebc_color.update();
}

void DruidCharacteristic::set_volume(float volume) {
  _volume.setText(QString::number(volume));
}

float DruidCharacteristic::volume() const { return _volume.text().toFloat(); }
