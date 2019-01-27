#pragma once

#include <QPushButton>
#include <QWidget>

class DruidMenu : public QWidget {
  Q_OBJECT

 public:
  DruidMenu();

 signals:
  void save();
  void load();

 private:
  void setupUi();

  QPushButton *_load;
  QPushButton *_save;
};
