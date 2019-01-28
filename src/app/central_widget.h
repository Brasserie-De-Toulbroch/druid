#pragma once

#include <QPointer>
#include <QWidget>

#include "boiling.h"
#include "db/db.h"
#include "fermentation.h"
#include "mashing.h"
#include "menu.h"
#include "notes.h"
#include "timer.h"
#include "ui_central_widget.h"
#include "volume.h"

class DruidCentralWidget : public QWidget, public Ui::DruidCentralWidget {
  Q_OBJECT

 public:
  DruidCentralWidget(const DruidDb* const db);

 private:
  void save();
  void load();
  DruidRecipe currentRecipe() const;

  DruidTimer _timer;
  DruidVolume _volume;
  DruidNotes _notes;
  DruidMenu _menu;
  DruidMashing _mashing;
  DruidBoiling _boiling;
  DruidFermentation _fermentation;
  const DruidDb* const _db;
};
