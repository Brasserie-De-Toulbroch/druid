#include <volume.h>

#include <iostream>

DruidVolume::DruidVolume() {
  setupUi(this);

  _lcd->setDigitCount(8);

  _sterilizer.diameter = 36.3;
  _sterilizer.height = 42.5;

  _boiler.diameter = 45.5;
  _boiler.height = 37.7;

  _fermentor.diameter = 37.0;
  _fermentor.height = 50.0;

  connect(_compute_sterilizer, &QPushButton::clicked, this,
          &DruidVolume::compute_sterilizer);
  connect(_compute_boiler, &QPushButton::clicked, this,
          &DruidVolume::compute_boiler);
  connect(_compute_fermentor, &QPushButton::clicked, this,
          &DruidVolume::compute_fermentor);
}

void DruidVolume::compute_sterilizer() {
  const float height_from_top = _height_sterilizer->value();
  const float volume = volume_in_l(_sterilizer, height_from_top);
  _lcd->display(QString::number(volume, 'f', 1));
}

void DruidVolume::compute_fermentor() {
  const float height_from_top = _height_fermentor->value();
  const float volume = volume_in_l(_fermentor, height_from_top);
  _lcd->display(QString::number(volume, 'f', 1));
}

void DruidVolume::compute_boiler() {
  const float height_from_top = _height_boiler->value();
  const float volume = volume_in_l(_boiler, height_from_top);
  _lcd->display(QString::number(volume, 'f', 1));
}

float DruidVolume::volume_in_l(const Tun &tun,
                               const float height_from_top) const {
  const float surface = 3.14 * (tun.diameter / 2) * (tun.diameter / 2);
  float volume = tun.height * surface;

  if (height_from_top > 0) {
    volume -= surface * height_from_top;
  }

  return volume / 1000;
}
