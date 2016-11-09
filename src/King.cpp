#include "King.hpp"

King::King() {
  this->name = "";
  this->years = 0;
}

King::King(const char* name) {
  this->name = name;
}

void King::setYear(uint32_t year) {
  this->years = year;
}

uint32_t King::getYears() {
  return this->years;
}

void King::setName(const char* name) {
  this->name = name;
}

char* King::getName() {
  return (char*)this->name.c_str();
}
