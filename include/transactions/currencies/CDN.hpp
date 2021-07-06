#ifndef _CDN_HPP
#define _CDN_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Currency.hpp"

class CDN extends Currency {
public:
  virtual float value() const { return Currency::value() * 1.2; }
};

#endif // _CDN_HPP
