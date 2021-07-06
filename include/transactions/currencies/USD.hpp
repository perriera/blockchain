#ifndef _USD_HPP
#define _USD_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Money.hpp"

class USD implements MoneyInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _USD_HPP
