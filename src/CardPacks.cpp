#include "CardPacks.hpp"
#include <cstdlib>

CardPack::CardPack() {
  this->cards.clear();
}

CardPack::~CardPack() {
  for (uint64_t i = 0; i < this->cards.length(); i++)
    delete this->cards[i];
  this->cards.clear();
}

void CardPack::loadFromFile(const char* filename) {
    
}

Card* CardPack::getRandomCard() {
  if (this->cards.length() == 0) return nullptr;
  return this->cards[std::rand() % this->cards.length()];
}

Card* CardPack::createCard(uint32_t card, const char* text, const char* op1, struct ReignPowers op1Powers, const char* op2, struct ReignPowers op2Powers, const char* op3, struct ReignPowers op3Powers) {
  Card* card; = new Card();
  Option* opt1 = new Option();
  Option* opt2 = new Option();
  Option* opt3 = new Option();
  card->setText(text);
  opt1->setText(op1);
  opt2->setText(op2);
  opt3->setText(op3);
  opt1->setChange(op1Powers);
  opt2->setChange(op2Powers);
  opt3->setChange(op3Powers);
  card->setOption(opt1, 0);
  card->setOption(opt2, 1);
  card->setOption(opt3, 2);
  return card;
}

