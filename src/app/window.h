#pragma once

#include <QMainWindow>
#include <QScopedPointer>

#include <central_widget.h>

class DruidWindow : public QMainWindow {
  Q_OBJECT

 public:
  DruidWindow();

 private:
  QScopedPointer<DruidCentralWidget> _central_widget;
};
