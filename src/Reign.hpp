#ifndef __REIGN_HPP__
#define __REIGN_HPP__

#include "King.hpp"
#include "ReignPowers.hpp"

class Reign {
  private:
    King king;
    struct ReignPowers powers;

  public:
    Reign();
    Reign(struct ReignPowers powers);

    void setKingName (const char* name);
    char* getKingName ();

    void newYear();
    uint32_t getKingYears();

    void setReignPowers (struct ReignPowers power);
    struct ReignPowers getReignPowers ();
};

#endif /* __REIGN_HPP__ */
