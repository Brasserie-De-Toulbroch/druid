#pragma once

#include <QGroupBox>
#include <QLineEdit>

#include "db/malt.h"
#include "ui_mashing.h"

class DruidMashing : public QGroupBox, public Ui::DruidMashing {
  Q_OBJECT

 public:
  DruidMashing();

  QList<DruidMalt> malts() const;
  void set_malts(const QList<DruidMalt> &malts);

 private:
  QList<QLineEdit *> _malts;
  QList<QLineEdit *> _ebc;
  QList<QLineEdit *> _weight;
};
