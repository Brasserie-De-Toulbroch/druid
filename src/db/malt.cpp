#include "malt.h"

DruidMalt::DruidMalt(const QString &name, const int ebc, const int weight)
    : _name(name), _ebc(ebc), _weight(weight) {}

QString DruidMalt::name() const { return _name; }

void DruidMalt::set_name(const QString &name) { _name = name; }

int DruidMalt::ebc() const { return _ebc; }

void DruidMalt::set_ebc(const int ebc) { _ebc = ebc; }

int DruidMalt::weight() const { return _weight; }

void DruidMalt::set_weight(const int weight) { _weight = weight; }

bool DruidMalt::is_valid() const {
  return !_name.isEmpty() && _ebc != 0 && _weight != 0;
}
