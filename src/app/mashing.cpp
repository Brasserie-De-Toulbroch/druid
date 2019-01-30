#include "mashing.h"
#include "utils/ebc_colors.h"

DruidMashing::DruidMashing() {
  setupUi(this);

  QGridLayout *grid_layout = (QGridLayout *)layout();
  for (int j = 0; j < 4; j++) {
    QLineEdit *malt = new QLineEdit();
    grid_layout->addWidget(malt, j + 1, 0);
    _malts << malt;

    QLineEdit *ebc = new QLineEdit();
    grid_layout->addWidget(ebc, j + 1, 1);
    _ebc << ebc;

    QLineEdit *weight = new QLineEdit();
    grid_layout->addWidget(weight, j + 1, 2);
    _weight << weight;
  }
}

QList<DruidMalt> DruidMashing::malts() const {
  QList<DruidMalt> malts;

  for (int j = 0; j < _malts.size(); j++) {
    DruidMalt malt;
    malt.set_name(_malts[j]->text());
    malt.set_weight(_weight[j]->text().toInt());
    malt.set_ebc(_ebc[j]->text().toInt());

    malts << malt;
  }

  return malts;
}
