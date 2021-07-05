#ifndef _BUYER_HPP
#define _BUYER_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"

interface BuyerInterface {
  virtual std::string say_hello() const pure;
};

class Buyer implements BuyerInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _BUYER_HPP
