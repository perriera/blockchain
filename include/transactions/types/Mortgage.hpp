#ifndef _MORTGAGE_HPP
#define _MORTGAGE_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Transaction.hpp"

interface MortgageInterface extends TransactionInterface{};

class Mortgage implements MortgageInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _MORTGAGE_HPP
