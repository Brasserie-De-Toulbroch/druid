#include <getopt.h>

#include <iostream>

#include <QApplication>
#include <QFile>
#include <QFontDatabase>
#include <QTextStream>

#include <window.h>

void print_usage() { std::cout << "Usage: druid -d filename" << std::endl; }

int main(int argc, char **argv) {
  // parse command line options
  int opt = 0;
  QString database;

  static struct option long_options[] = {{"db", required_argument, 0, 'd'},
                                         {0, 0, 0, 0}};

  int long_index = 0;
  while ((opt = getopt_long(argc, argv, "d:", long_options, &long_index)) !=
         -1) {
    switch (opt) {
      case 'd':
        database = QString(optarg);
        break;
      default:
        print_usage();
        exit(EXIT_FAILURE);
    }
  }

  if (database.isEmpty()) {
    print_usage();
    exit(EXIT_FAILURE);
  }

  // open database
  DruidDb db(database);
  if (!db.is_ready()) {
    std::cerr << "Invalid database" << std::endl;
    exit(EXIT_FAILURE);
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
  DruidWindow window(&db);
  window.show();

  return app.exec();
}
