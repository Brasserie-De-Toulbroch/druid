#include <iostream>

#include <QApplication>
#include <QFile>
#include <QFontDatabase>
#include <QTextStream>

#include <window.h>

int main(int argc, char **argv) {
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
  }

  // load stylesheet
  QFile f(":qdarkstyle/style.qss");
  if (f.exists()) {
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream ts(&f);
    app.setStyleSheet(ts.readAll());
  } else {
    std::cerr << "Unable to set stylesheet, file not found." << std::endl;
  }

  // open database
  DruidDb db("/tmp/druid.db");
  if (!db.is_ready()) {
    std::cerr << "Invalid database" << std::endl;
    return true;
  }

  // create main window
  DruidWindow window(&db);
  window.show();

  return app.exec();
}
