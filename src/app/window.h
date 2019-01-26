#pragma once

#include <QMainWindow>
#include <QScopedPointer>

#include <central_widget.h>
#include <db/db.h>

class DruidWindow : public QMainWindow {
  Q_OBJECT

 public:
  DruidWindow(const DruidDb* const db);

 private:
  QScopedPointer<DruidCentralWidget> _central_widget;
};
