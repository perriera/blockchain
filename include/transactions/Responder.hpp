#ifndef _RESPONDER_HPP
#define _RESPONDER_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Transaction.hpp"

interface ResponderInterface {
  virtual Transaction respond(TransactionInterface * transaction) pure;
};

#endif // _RESPONDER_HPP
