#include "Option.hpp"

Option::Option() {
  this->change.church = 0;
  this->change.people = 0;
  this->change.army = 0;
  this->change.money = 0;
}

Option::Option(const char* text, struct ReignPowers powers) {
  this->text = text;
  this->change = powers;
}

Option::Option(Option* option) {
  this->text = option->text;
  this->change.church = option->change.church;
  this->change.people = option->change.people;
  this->change.army = option->change.army;
  this->change.money = option->change.money;
}

void Option::setText (const char* text) {
  this->text = text;
}

char* Option::getText () {
  return (char*)this->text.c_str();
}

void Option::setChange (struct ReignPowers powers) {
  this->change = powers;
}

struct ReignPowers Option::getChange() {
  return change;
}
