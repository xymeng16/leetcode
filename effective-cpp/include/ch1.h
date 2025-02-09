//
// Created by Xiangyi Meng on 9/2/2025.
//

#ifndef CH1_H
#define CH1_H

#include <common.h>
#include <iostream>

class GamePlayer {
private:
  static const int NumTurns =
      5; // a declaration of a static const integral member
  enum {
    NumsTurnsEnum = 5
  }; // an enum hack to declare a static const integral
     // member
  int scores[NumTurns];

public:
  static const int getNumTurns() { return *&NumTurns; }
  // static const int getNumsTurnsEnum() {
  //   return *&NumsTurnsEnum;
  // } // ERROR, cannot take the address of an enum
};

// const member functions
class TextBlock {
public:
  explicit TextBlock(const std::string &t) : text(t) {};
  const char &operator[](std::size_t position) const {
    // do a lot of check, log, etc., stuff
    return text[position];
  }
  char &operator[](std::size_t position) {
    // we first convert *this to a const TextBlock &, to avoid recursion
    // and then const_cast it to a non-const char &
    return const_cast<char &>(static_cast<const TextBlock &>(*this)[position]);
  } // always let non-const member function call the const member function

private:
  std::string text;
};

class CTextBlock {
public:
  char &operator[](std::size_t position) const {
    return pText[position];
  } // BAD, a const member function returns a non-const reference
  std::size_t length() const {
    if (!length_is_valid) {
      text_length = std::strlen(pText);
      length_is_valid = true;
    }
    return text_length;
  }

private:
  char *pText;
  mutable std::size_t text_length;
  mutable bool length_is_valid;
};
#endif // CH1_H
