#ifndef __KING_HPP__
#define __KING_HPP__

#include <cstdint>
#include <string>

class King {
  private:
    std::string name;
    uint32_t years;

  public:
    King();
    King(const char* name);

    void setYear(uint32_t year);
    uint32_t getYears();

    void setName (const char* name);
    char* getName ();
};

#endif /* __KING_HPP__ */
