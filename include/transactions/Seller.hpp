#ifndef _SELLER_HPP
#define _SELLER_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"

interface SellerInterface {
  virtual std::string say_hello() const pure;
};

class Seller implements SellerInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _SELLER_HPP
