#ifndef _PAYMENT_HPP
#define _PAYMENT_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"

interface PaymentInterface {
  virtual std::string say_hello() const pure;
};

class Payment implements PaymentInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _PAYMENT_HPP
