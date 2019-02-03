#include "mashing.h"
#include "utils/ebc_colors.h"

DruidMashing::DruidMashing() {
  setupUi(this);

  QGridLayout *grid_layout = (QGridLayout *)layout();
  const int malts = 6;
  for (int j = 0; j < malts; j++) {
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

  QLabel *label_tmp = new QLabel("Temperature");
  grid_layout->addWidget(label_tmp, malts + 2, 0);
  grid_layout->addWidget(&_tmp, malts + 2, 1);

  QLabel *label_water = new QLabel("Water Volume");
  grid_layout->addWidget(label_water, malts + 3, 0);
  grid_layout->addWidget(&_vol_water, malts + 3, 1);

  QLabel *label_wort = new QLabel("Wort Volume");
  grid_layout->addWidget(label_wort, malts + 4, 0);
  grid_layout->addWidget(&_vol_wort, malts + 4, 1);
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

void DruidMashing::set_malts(const QList<DruidMalt> &malts) {
  QGridLayout *grid_layout = (QGridLayout *)layout();

  for (int j = 0; j < _malts.size(); j++) {
    QLineEdit *malt =
        (QLineEdit *)grid_layout->itemAtPosition(j + 1, 0)->widget();
    QString malt_str;
    if (j < malts.size()) {
      malt_str = malts[j].name();
    }
    malt->setText(malt_str);

    QLineEdit *ebc =
        (QLineEdit *)grid_layout->itemAtPosition(j + 1, 1)->widget();
    ebc->clear();
    if (j < malts.size()) {
      ebc->setText(QString::number(malts[j].ebc()));
    }

    QLineEdit *weight =
        (QLineEdit *)grid_layout->itemAtPosition(j + 1, 2)->widget();
    weight->clear();
    if (j < malts.size()) {
      weight->setText(QString::number(malts[j].weight()));
    }
  }
}
