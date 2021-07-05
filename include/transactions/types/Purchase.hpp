#ifndef _PURCHASE_HPP
#define _PURCHASE_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Transaction.hpp"

interface PurchaseInterface extends TransactionInterface{};

class Purchase implements PurchaseInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _PURCHASE_HPP
