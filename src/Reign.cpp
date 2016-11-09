#include "Reign.hpp"

Reign::Reign() {
  this->powers.church = 0;
  this->powers.people = 0;
  this->powers.army = 0;
  this->powers.money = 0;
}

Reign::Reign(struct ReignPowers powers) {
  this->powers = powers;
}

void Reign::setKingName(const char* name) {
  this->king.setName(name);
}

char* Reign::getKingName() {
  return this->king.getName();
}

void Reign::newYear() {
  this->king.setYear(this->getKingYears()+1);
}

uint32_t Reign::getKingYears() {
  return this->king.getYears();
}

void Reign::setReignPowers (struct ReignPowers power) {
  this->powers = power;
}

struct ReignPowers Reign::getReignPowers() {
  return this->powers;
}
