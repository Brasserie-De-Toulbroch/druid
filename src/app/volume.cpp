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

  connect(_sterilizer_to_volume, &QPushButton::clicked, this,
          &DruidVolume::sterilizer_to_volume);
  connect(_boiler_to_volume, &QPushButton::clicked, this,
          &DruidVolume::boiler_to_volume);
  connect(_fermentor_to_volume, &QPushButton::clicked, this,
          &DruidVolume::fermentor_to_volume);
  connect(_sterilizer_to_height, &QPushButton::clicked, this,
          &DruidVolume::sterilizer_to_height);
  connect(_boiler_to_height, &QPushButton::clicked, this,
          &DruidVolume::boiler_to_height);
  connect(_fermentor_to_height, &QPushButton::clicked, this,
          &DruidVolume::fermentor_to_height);
}

void DruidVolume::sterilizer_to_volume() {
  const float height_from_top = _value_sterilizer->value();
  const float volume = volume_in_l(_sterilizer, height_from_top);
  _lcd->display(QString::number(volume, 'f', 1));
}

void DruidVolume::fermentor_to_volume() {
  const float height_from_top = _value_fermentor->value();
  const float volume = volume_in_l(_fermentor, height_from_top);
  _lcd->display(QString::number(volume, 'f', 1));
}

void DruidVolume::boiler_to_volume() {
  const float height_from_top = _value_boiler->value();
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

void DruidVolume::sterilizer_to_height() {
  const float volume = _value_sterilizer->value();
  const float height_from_top = height_in_cm(_sterilizer, volume);
  _lcd->display(QString::number(height_from_top, 'f', 1));
}

void DruidVolume::boiler_to_height() {
  const float volume = _value_boiler->value();
  const float height_from_top = height_in_cm(_boiler, volume);
  _lcd->display(QString::number(height_from_top, 'f', 1));
}

void DruidVolume::fermentor_to_height() {
  const float volume = _value_fermentor->value();
  const float height_from_top = height_in_cm(_fermentor, volume);
  _lcd->display(QString::number(height_from_top, 'f', 1));
}

float DruidVolume::height_in_cm(const Tun &tun, const float volume) const {
  const float surface = 3.14 * (tun.diameter / 2) * (tun.diameter / 2);
  const float height = (volume * 1000) / surface;

  return tun.height - height;
}
