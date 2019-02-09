#include "recipe.h"

void DruidRecipe::set_title(const QString &title) { _title = title; }

bool DruidRecipe::is_valid() const { return !_title.isEmpty(); }

QString DruidRecipe::title() const { return _title; }

void DruidRecipe::set_notes(const QString &notes) { _notes = notes; }

QString DruidRecipe::notes() const { return _notes; }

void DruidRecipe::add_malt(const DruidMalt &malt) { _malts.append(malt); }

QList<DruidMalt> DruidRecipe::malts() const { return _malts; }

void DruidRecipe::set_volume(int volume) { _volume = volume; }

int DruidRecipe::volume() const { return _volume; }

void DruidRecipe::set_mashing_water_volume(int volume) {
  _mashing_water_volume = volume;
}

int DruidRecipe::mashing_water_volume() const { return _mashing_water_volume; }

void DruidRecipe::set_mashing_temperature(int temp) {
  _mashing_temperature = temp;
}

int DruidRecipe::mashing_temperature() const { return _mashing_temperature; }

void DruidRecipe::set_mashing_wort_volume(int volume) {
  _mashing_wort_volume = volume;
}

int DruidRecipe::mashing_wort_volume() const { return _mashing_wort_volume; }

void DruidRecipe::set_mashing_duration(const int duration) {
  _mashing_duration = duration;
}

int DruidRecipe::mashing_duration() const { return _mashing_duration; }

void DruidRecipe::set_yeast(const QString &yeast) { _yeast = yeast; }

QString DruidRecipe::yeast() const { return _yeast; }
