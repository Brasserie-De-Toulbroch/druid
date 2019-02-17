#pragma once

#include <QString>

class DS18B20 {
 public:
  DS18B20(const QString &id, const QString &path = "/sys/bus/w1/devices/");

  float temperature() const;

 private:
  const QString _path;
};
