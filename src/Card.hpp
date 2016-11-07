#ifndef __CARD_HPP__
#define __CARD_HPP__

#include <string>
#include <cstdint>
#include "Option.hpp"

#define MAX_OPTIONS 3

class Card {
  private:
    std::string text;
    Option ops[MAX_OPTIONS];

  public:
    Cards();

    void setText (const char* text);
    char* getText ();

    void setOption(Option& option, uint32_t i);
    Option& getOption();
};

#ifndef /* __CARD_HPP__ */
