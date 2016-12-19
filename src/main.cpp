#include <iostream>
#include "Reign.hpp"
#include "Card.hpp"
#include "CardGame.hpp"
#include "CardPacks.hpp"

int main (int argc, char* argv[]) {

  Reign* reino = new Reign();
  CardGame cardGame;

  reino->setKingName("OdnetninI");
  reino->setReignPowers({10,5,20,35});
  CardPack cards;
  cards.loadFromFile("CardPack1.cards");

  cardGame.newGame(reino);
  cardGame.gameLoop(&cards);

  return 0;
}
