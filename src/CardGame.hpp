#ifndef __CARDGAME_HPP__
#define __CARDGAME_HPP__

#include "Reign.hpp"

class CardGame {
  private:
    Reign* actualReign;

  public:
    // Before new game, old game is deleted (free)
    void newGame(Reign* reign);

    Reign* getLastGame();

    void gameLoop();
};

#endif /* __CardGAME_HPP__ */
