#ifndef __CARDGAME_HPP__
#define __CARDGAME_HPP__

#include "Reign.hpp"

class CardPack;

class CardGame {
  private:
    Reign* actualReign;

  public:
    CardGame();
    ~CardGame();
    // Before new game, old game is deleted (free)
    void newGame(Reign* reign);
    bool isLose();

    Reign* getLastGame();

    void gameLoop(CardPack* cards);
};

#endif /* __CARDGAME_HPP__ */
