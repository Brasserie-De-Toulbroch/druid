// 7c 01 4b 46 7f ff 04 10 09 : crc=09 YES
// 7c 01 4b 46 7f ff 04 10 09 t=23750[/bash]

#include <QDir>
#include <QTest>
#include <QTextStream>

#include <iostream>

#include "dev/ds18b20/ds18b20.h"

class TestDS18B20 : public QObject {
  Q_OBJECT
 private slots:
  void test();
};

void TestDS18B20::test() {
  const QString slaveid("ds18b20_slaveid");
  const QString directory("/tmp");
  const QString path = QString("%1/%2").arg(directory, slaveid);

  QDir dir;
  dir.mkdir(path);

  const QString filename = QString("%1/w1_slave").arg(path);
  QFile file(filename);
  if (file.open(QIODevice::ReadWrite)) {
    QTextStream stream(&file);
    stream << "7c 01 4b 46 7f ff 04 10 09 : crc=09 YES" << endl;
    stream << "7c 01 4b 46 7f ff 04 10 09 t=23750[/bash]" << endl;
  }

  DS18B20 ds18b20(slaveid, directory);
  QCOMPARE(ds18b20.temperature(), 23.75);

  file.remove();
  dir.rmdir(path);
}

QTEST_MAIN(TestDS18B20)
#include "ds18b20.moc"
