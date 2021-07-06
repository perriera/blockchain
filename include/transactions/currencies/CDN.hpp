#ifndef _CDN_HPP
#define _CDN_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Money.hpp"

class CDN implements MoneyInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _CDN_HPP
