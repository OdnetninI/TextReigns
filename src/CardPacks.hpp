#ifndef __CARD_PACKS_HPP__
#define __CARD_PACKS_HPP__

#include "Card.hpp"
#include <vector>

class CardPack {
  private
    std::vector<Card*> cards;

    Card* createCard (uint32_t card, const char* text, const char* op1, struct ReignPowers op1Powers, const char* op2, struct ReignPowers op2Powers, const char* op3, struct ReignPowers op3Powers); 
    
  public:
    CardPack();
    ~CardPack();

    void loadFromFile(const char* filename);
    Card* getRandomCard();
};

#endif /* __CARD_PACKS_HPP__ */
