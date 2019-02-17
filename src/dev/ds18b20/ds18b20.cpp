#include <QFile>
#include <QTextStream>

#include <iostream>

#include <ds18b20.h>

DS18B20::DS18B20(const QString &id, const QString &path)
    : _path(QString("%1/%2/w1_slave").arg(path, id)) {}

float DS18B20::temperature() const {
  float temperature = -1.0;

  QFile infile(_path);
  if (infile.open(QIODevice::ReadOnly)) {
    QTextStream in(&infile);
    while (!in.atEnd()) {
      const QString line = in.readLine();
      if (line.contains("t=")) {
        const int idx = line.indexOf("=") + 1;
        const QString temp = line.right(line.size() - idx).left(4);
        temperature = temp.toFloat() / 100;
        break;
      }
    }
    infile.close();
  }

  return temperature;
}
