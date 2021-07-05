#ifndef _DEDITCARD_HPP
#define _DEDITCARD_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Transaction.hpp"

interface DebitCardInterface extends TransactionInterface{};

class DebitCard implements DebitCardInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _DEDITCARD_HPP
