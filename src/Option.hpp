#ifndef __OPTION_HPP__
#define __OPTION_HPP__

#include <string>
#include "ReignPowers.hpp"

class Option {
  private:
    std::string text;
    struct ReignPowers change;

  public:
    Option();
    Option(const char* text, struct ReignPowers powers);
    Option(Option& option);

    void setText (const char* text);
    char* getText ();

    void setChange (struct ReignPowers powers);
    struct ReignPowers getChange ();
};

#ifndef /* __OPTION_HPP__ */
