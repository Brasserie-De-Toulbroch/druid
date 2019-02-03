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
