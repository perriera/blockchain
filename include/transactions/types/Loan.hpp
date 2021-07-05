#ifndef _LOAN_HPP
#define _LOAN_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Transaction.hpp"

interface LoanInterface extends TransactionInterface{};

class Loan implements LoanInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _LOAN_HPP
