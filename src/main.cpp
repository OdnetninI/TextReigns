#include <iostream>
#include "Reign.hpp"
#include "Card.hpp"
#include "CardGame.hpp"

#define MAX_CARDS 2
Card* cards[MAX_CARDS];

void initializeCards() {
  for (uint32_t card = 0; card < MAX_CARDS; card++)
    cards[card] = nullptr;
}

void addCard (uint32_t card, const char* text, const char* op1, struct ReignPowers op1Powers, const char* op2, struct ReignPowers op2Powers, const char* op3, struct ReignPowers op3Powers) {
  if (card >= MAX_CARDS) return;
  if (cards[card] != nullptr) delete cards[card];
  cards[card] = new Card();
  Option* opt1 = new Option();
  Option* opt2 = new Option();
  Option* opt3 = new Option();
  cards[card]->setText(text);
  opt1->setText(op1);
  opt2->setText(op2);
  opt3->setText(op3);
  opt1->setChange(op1Powers);
  opt2->setChange(op2Powers);
  opt3->setChange(op3Powers);
  cards[card]->setOption(opt1, 0);
  cards[card]->setOption(opt2, 1);
  cards[card]->setOption(opt3, 2);
}

int main (int argc, char* argv[]) {

  Reign reino;
  CardGame cardGame;

  reino.setKingName("OdnetninI");
  reino.setReignPowers({10,5,20,35});
  initializeCards();
  addCard(0, "Hay que construir un establo", "Hagamoslo", {0,15,0,-20}, "NO!", {0,-10,0,0}, "Haced algo más pequeño", {0,5,0,-10});
  addCard(1, "Atacad el reino vecino", "A LA CARGA", {0,-5,-10,-15}, "NO!", {5,0,0,0}, "Hagamos un Pacto", {0,5,-5,-10});

  cardGame.newGame(&reino);
  cardGame.gameLoop(cards);

  return 0;
}
