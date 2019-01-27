#include <QHBoxLayout>

#include "menu.h"

DruidMenu::DruidMenu() {
  setupUi();

  connect(_save, &QPushButton::clicked, this, &DruidMenu::save);
  connect(_load, &QPushButton::clicked, this, &DruidMenu::load);
}

void DruidMenu::setupUi() {
  QHBoxLayout *layout = new QHBoxLayout();

  _save = new QPushButton("Save");
  layout->addWidget(_save);

  _load = new QPushButton("Load");
  layout->addWidget(_load);

  setLayout(layout);
}
