#include "recipe.h"

void DruidRecipe::setTitle(const QString &title) { _title = title; }

bool DruidRecipe::is_valid() const { return !_title.isEmpty(); }

QString DruidRecipe::title() const { return _title; }

void DruidRecipe::setNotes(const QString &notes) { _notes = notes; }

QString DruidRecipe::notes() const { return _notes; }
