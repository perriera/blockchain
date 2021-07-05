#ifndef _BANKACCOUNT_HPP
#define _BANKACCOUNT_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Transaction.hpp"

interface BankAccountInterface extends TransactionInterface{};

class BankAccount implements BankAccountInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _BANKACCOUNT_HPP
