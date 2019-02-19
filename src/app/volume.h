#pragma once

#include <QGroupBox>

#include "ui_volume.h"

class DruidVolume : public QGroupBox, public Ui::DruidVolume {
  Q_OBJECT

 public:
  struct Tun {
    float diameter;  // cm
    float height;    // cm
  };

  DruidVolume();

 private:
  void sterilizer_to_volume();
  void boiler_to_volume();
  void fermentor_to_volume();
  void sterilizer_to_height();
  void boiler_to_height();
  void fermentor_to_height();
  float volume_in_l(const Tun &tun, float height_from_top) const;
  float height_in_cm(const Tun &tun, float volume) const;

  Tun _sterilizer;
  Tun _boiler;
  Tun _fermentor;
};
