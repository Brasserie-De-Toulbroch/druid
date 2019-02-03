#include <QLabel>

#include "fermentation.h"

DruidFermentation::DruidFermentation() {
  setupUi(this);

  QFormLayout *form_layout = (QFormLayout *)layout();
  form_layout->addRow(new QLabel("Yeast"), &_yeast);
}

void DruidFermentation::set_yeast(const QString &yeast) {
  _yeast.setText(yeast);
}

QString DruidFermentation::yeast() const { return _yeast.text(); }
