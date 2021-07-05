#ifndef _CREDITCARD_HPP
#define _CREDITCARD_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Transaction.hpp"

interface CreditCardInterface extends TransactionInterface{};

class CreditCard implements CreditCardInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _CREDITCARD_HPP
