#include <QListWidgetItem>

#include <db_selector.h>

DruidDbSelector::DruidDbSelector(const DruidDb *db) : _db(db) {
  setupUi(this);

  for (const DruidRecipe &recipe : db->recipes()) {
    QListWidgetItem *item = new QListWidgetItem();
    item->setText(recipe.title());
    _list->addItem(item);
  }

  connect(_cancel, &QPushButton::clicked, this, &DruidDbSelector::close);
  connect(_load, &QPushButton::clicked, this, &DruidDbSelector::close);
}

DruidRecipe DruidDbSelector::recipe() const {
  DruidRecipe selected;

  QList<QListWidgetItem *> selection = _list->selectedItems();
  if (selection.isEmpty()) {
    return selected;
  }

  for (const DruidRecipe &recipe : _db->recipes()) {
    if (selection[0]->text().compare(recipe.title()) == 0) {
      selected = recipe;
    }
  }

  return selected;
}
