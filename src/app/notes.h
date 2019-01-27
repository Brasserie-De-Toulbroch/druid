#pragma once

#include <QGroupBox>

#include "ui_notes.h"

class DruidNotes : public QGroupBox, public Ui::DruidNotes {
  Q_OBJECT

 public:
  DruidNotes();

  QString text() const;
};
