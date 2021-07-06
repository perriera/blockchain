#ifndef _USD_HPP
#define _USD_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Currency.hpp"

class USD implements CurrencyInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _USD_HPP
