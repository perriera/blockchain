#ifndef _RESPONDER_HPP
#define _RESPONDER_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Transaction.hpp"

interface ResponderInterface {
  virtual Transaction respond(TransactionInterface * transaction) pure;
  virtual Transaction liquify(const AssetInterface *asset) pure;
  virtual Transaction deposit(const CurrencyInterface *currency) pure;
};

#endif // _RESPONDER_HPP
