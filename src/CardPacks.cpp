#include "CardPacks.hpp"
#include <cstdlib>
#include <fstream>

CardPack::CardPack() {
  this->cards.clear();
}

CardPack::~CardPack() {
  for (uint64_t i = 0; i < this->cards.size(); i++)
    delete this->cards[i];
  this->cards.clear();
}

void CardPack::loadFromFile(const char* filename) {
  std::ifstream file(filename);
  if (!file.is_open()) return;

  while (file.good()) {
    std::string text, msg1, msg2, msg3;
    int p1,p2,p3,p4;
    int p5,p6,p7,p8;
    int p9,p10,p11,p12;
    std::getline(file, text);
    std::getline(file, msg1);
    file >> p1 >> p2 >> p3 >> p4;
    file.ignore();
    std::getline(file, msg2);
    file >> p5 >> p6 >> p7 >> p8;
    file.ignore();
    std::getline(file, msg3);
    file >> p9 >> p10 >> p11 >> p12;
    file.ignore();
    Card* card = createCard(text.c_str(), msg1.c_str(), {p1,p2,p3,p4}, msg2.c_str(), {p5,p6,p7,p8}, msg3.c_str(), {p9,p10,p11,p12});
    this->cards.push_back(card);
  }

  file.close();
}

Card* CardPack::getRandomCard() {
  if (this->cards.size() == 0) return nullptr;
  return this->cards[std::rand() % this->cards.size()];
}

Card* CardPack::createCard(const char* text, const char* op1, struct ReignPowers op1Powers, const char* op2, struct ReignPowers op2Powers, const char* op3, struct ReignPowers op3Powers) {
  Card* card = new Card();
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

