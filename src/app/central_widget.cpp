#include <iostream>

#include "central_widget.h"
#include "db_selector.h"
#include "utils/ebc_colors.h"

DruidCentralWidget::DruidCentralWidget(const DruidDb* const db) : _db(db) {
  setupUi(this);

  _top_layout->insertWidget(0, &_menu);

  _left_layout->addWidget(&_mashing);
  _left_layout->addWidget(&_boiling);

  _mid_layout->addWidget(&_fermentation);
  _mid_layout->addWidget(&_characteristic);

  _right_layout->addWidget(&_timer);
  _right_layout->addWidget(&_volume);
  _right_layout->addWidget(&_notes);

  connect(&_menu, &DruidMenu::save, this, &DruidCentralWidget::save);
  connect(&_menu, &DruidMenu::load, this, &DruidCentralWidget::load);
  connect(&_characteristic, &DruidCharacteristic::update_ebc, this,
          &DruidCentralWidget::update_ebc);
}

void DruidCentralWidget::load() {
  DruidDbSelector selector(_db);
  selector.exec();

  const DruidRecipe recipe = selector.recipe();

  if (recipe.is_valid()) {
    _title->setText(recipe.title());
    _notes.setText(recipe.notes());
    _mashing.set_malts(recipe.malts());
    _mashing.set_water_volume(recipe.mashing_water_volume());
    _mashing.set_wort_volume(recipe.mashing_wort_volume());
    _mashing.set_temperature(recipe.mashing_temperature());
    _mashing.set_duration(recipe.mashing_duration());
    _characteristic.set_volume(recipe.volume());
    _fermentation.set_yeast(recipe.yeast());

    update_ebc();
  }
}

void DruidCentralWidget::save() {
  const DruidRecipe recipe = currentRecipe();

  if (!_db->recipe_exists(recipe.title())) {
    _db->recipe_add(recipe);
  } else {
    _db->recipe_update(recipe);
  }
}

DruidRecipe DruidCentralWidget::currentRecipe() const {
  DruidRecipe recipe;

  recipe.set_title(_title->text());
  recipe.set_notes(_notes.text());
  recipe.set_volume(_characteristic.volume());
  recipe.set_mashing_temperature(_mashing.temperature());
  recipe.set_mashing_wort_volume(_mashing.wort_volume());
  recipe.set_mashing_water_volume(_mashing.water_volume());
  recipe.set_mashing_duration(_mashing.duration());
  recipe.set_yeast(_fermentation.yeast());

  for (const auto malt : _mashing.malts()) {
    recipe.add_malt(malt);
  }

  return recipe;
}

void DruidCentralWidget::update_ebc() {
  const float ebc =
      DruidUtils::to_ebc(currentRecipe().malts(), _characteristic.volume());
  _characteristic.set_ebc(ebc);
}
