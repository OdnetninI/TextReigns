#include "Card.hpp"

Card::Card() {}

void Card::setText(const char* text) {
  this->text = text;
}

char* Card::getText () {
  return (char*)this->text.c_str();
}

void Card::setOption(Option& option, uint32_t i) {
  if (i >= MAX_OPTIONS) return;
  this->ops[i] = Option(option);
}

Option* Card::getOption (uint32_t i) {
  if (i >= MAX_OPTIONS) return nullptr;
  return &this->ops[i];
}
