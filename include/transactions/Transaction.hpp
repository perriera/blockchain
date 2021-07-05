#ifndef _TRANSACTION_HPP
#define _TRANSACTION_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"

interface TransactionInterface {
  virtual std::string say_hello() const pure;
};

class Transaction implements TransactionInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _TRANSACTION_HPP
