#ifndef _USD_HPP
#define _USD_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Currency.hpp"

class USD extends Currency {
public:
  virtual float value() const { return Currency::value() * 1.5; }
};

#endif // _USD_HPP
