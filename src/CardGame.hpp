#ifndef __CARDGAME_HPP__
#define __CARDGAME_HPP__

#include "Reign.hpp"

class Card;

class CardGame {
  private:
    Reign* actualReign;

  public:
    CardGame();
    // Before new game, old game is deleted (free)
    void newGame(Reign* reign);

    Reign* getLastGame();

    void gameLoop(Card** cards);
};

#endif /* __CARDGAME_HPP__ */
