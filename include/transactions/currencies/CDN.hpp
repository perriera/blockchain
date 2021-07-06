#ifndef _CDN_HPP
#define _CDN_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Currency.hpp"

class CDN implements CurrencyInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _CDN_HPP
