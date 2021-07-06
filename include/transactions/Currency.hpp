#ifndef _CURRENCY_HPP
#define _CURRENCY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"

interface CurrencyInterface {
  virtual std::string say_hello() const pure;
};

#endif // _CURRENCY_HPP
