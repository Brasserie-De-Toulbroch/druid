#include <getopt.h>

#include <iostream>

#include <QApplication>
#include <QFile>
#include <QFontDatabase>
#include <QTextStream>

#include <window.h>
#include "ds18b20/ds18b20.h"

int main(int argc, char **argv) {
  // parse command line options
  int opt = 0;
  QString ds18b20_id;

  static struct option long_options[] = {{"ds18b20", required_argument, 0, 'd'},
                                         {0, 0, 0, 0}};

  int long_index = 0;
  while ((opt = getopt_long(argc, argv, "t:", long_options, &long_index)) !=
         -1) {
    switch (opt) {
      case 't':
        ds18b20_id = QString(optarg);
        break;
      default:
        exit(EXIT_FAILURE);
    }
  }

  // init application
  QApplication app(argc, argv);

  // load font
  const int id = QFontDatabase::addApplicationFont(":fonts/lobster.ttf");
  if (id != -1) {
    const QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    const QFont font(family, 16);
    app.setFont(font);
  } else {
    std::cerr << "Unable to set lobster font." << std::endl;
    exit(EXIT_FAILURE);
  }

  // load stylesheet
  QFile f(":qdarkstyle/style.qss");
  if (f.exists()) {
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream ts(&f);
    app.setStyleSheet(ts.readAll());
  } else {
    std::cerr << "Unable to set stylesheet, file not found." << std::endl;
    exit(EXIT_FAILURE);
  }

  // create main window
  DruidWindow window;

  if (!ds18b20_id.isEmpty()) {
    DS18B20 sensor(ds18b20_id);
    DruidCentralWidget *widget =
        qobject_cast<DruidCentralWidget *>(window.centralWidget());
    widget->temperature_widget()->set_sensor(&sensor);
  }

  window.show();

  return app.exec();
}
