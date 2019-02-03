#pragma once

#include <QList>
#include <QString>

#include "malt.h"

class DruidRecipe {
 public:
  DruidRecipe() = default;

  bool is_valid() const;

  void set_title(const QString &title);
  QString title() const;

  void set_notes(const QString &notes);
  QString notes() const;

  void add_malt(const DruidMalt &malt);
  QList<DruidMalt> malts() const;

  void set_volume(int volume);
  int volume() const;

  void set_mashing_water_volume(int volume);
  int mashing_water_volume() const;

  void set_mashing_temperature(int temp);
  int mashing_temperature() const;

  void set_mashing_wort_volume(int volume);
  int mashing_wort_volume() const;

  void set_mashing_duration(int duration);
  int mashing_duration() const;

 private:
  QString _title;
  QString _notes;
  QList<DruidMalt> _malts;
  int _volume;
  int _mashing_temperature;
  int _mashing_wort_volume;
  int _mashing_water_volume;
  int _mashing_duration;
};
