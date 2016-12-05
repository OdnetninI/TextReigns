#include "CardGame.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Card.hpp"
#include "Reign.hpp"
#include <cstdint>

#define MAX_CARDS 2

CardGame::CardGame() {
  std::srand(std::time(nullptr));
  this->actualReign = nullptr;
}

CardGame::~CardGame() {
  if(this->actualReign) delete this->actualReign;
}

void CardGame::newGame(Reign* reign) {
  if(this->actualReign) delete this->actualReign; // Only now, in future no
  this->actualReign = reign;
}

Reign* CardGame::getLastGame() {
  return this->actualReign;
}

std::ostream& operator<<(std::ostream& cout, struct ReignPowers powers) {
  cout << "Iglesia: " << powers.church;
  cout << " Gente: " << powers.people;
  cout << " Ejercito: " << powers.army;
  cout << " Dinero: " << powers.money;
  return cout;
}

std::ostream& operator<<(std::ostream& cout, Card& card) {
  cout << "Text: " << card.getText();
  cout << "\nOption1: " << card.getOption(0)->getText() << " " << card.getOption(0)->getChange();
  cout << "\nOption2: " << card.getOption(1)->getText() << " " << card.getOption(1)->getChange();
  cout << "\nOption3: " << card.getOption(2)->getText() << " " << card.getOption(2)->getChange();
  return cout;
}

std::ostream& operator<<(std::ostream& cout, Card* card) {
  cout << *card;
  return cout;
}

struct ReignPowers operator+ (struct ReignPowers a, struct ReignPowers b) {
  int32_t church = a.church + b.church;
  int32_t people = a.people + b.people;
  int32_t army = a.army + b.army;
  int32_t money = a.money + b.money;
  return {church, people, army, money};
}

bool CardGame::isLose () {
  struct ReignPowers powers = this->actualReign->getReignPowers();
  if (powers.church <= 0 || powers.people <= 0 || powers.army <= 0 || powers.money <= 0) return true;
  return false;
}

void CardGame::gameLoop(Card** cards) {
  if (!this->actualReign) {
    std::cerr << "ERROR: No Reign was initialized" << "\n";
    exit(1);
  }

  while (!this->isLose()) {
    // Update Part1
    uint32_t card = std::rand()%MAX_CARDS;
    
    // Draw
    std::cout << "Rey: " << this->actualReign->getKingName() << " Años al Poder: " << this->actualReign->getKingYears() << "\n";
    std::cout << this->actualReign->getReignPowers() << "\n";
    std::cout << cards[card] << "\n";
    
    // Wait Input
    uint32_t opcion = 0;
    do {
      std::cin >> opcion;
      opcion--;
    } while (opcion >= MAX_OPTIONS);
    
    // Update Part2
    this->actualReign->setReignPowers(this->actualReign->getReignPowers()+cards[card]->getOption(opcion)->getChange());
    this->actualReign->newYear();
  }

  std::cout << "HAS PERDIDO" << "\n";
  std::cout << "EL REY HA MUERTO" << "\n";
  std::cout << this->actualReign->getReignPowers() << "\n";
}
