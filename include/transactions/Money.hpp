#ifndef _MONEY_HPP
#define _MONEY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"

interface MoneyInterface {
  virtual std::string say_hello() const pure;
};

#endif // _MONEY_HPP
