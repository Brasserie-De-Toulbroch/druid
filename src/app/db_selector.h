#pragma once

#include <QDialog>

#include "db/db.h"
#include "ui_db_selector.h"

class DruidDbSelector : public QDialog, public Ui::DruidDbSelector {
  Q_OBJECT

 public:
  DruidDbSelector(const DruidDb *db);

  DruidRecipe recipe() const;

 private:
  const DruidDb *_db;
};
