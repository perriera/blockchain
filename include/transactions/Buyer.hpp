#ifndef _BUYER_HPP
#define _BUYER_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Initiator.hpp"
#include "Responder.hpp"
#include "Transaction.hpp"

interface BuyerInterface extends InitiatorInterface with ResponderInterface {
  virtual std::string say_hello() const pure;
};

class Buyer implements BuyerInterface {
public:
  virtual std::string say_hello() const;
  virtual Transaction initiate(const AssetInterface &asset,
                               const CurrencyInterface &currency);
  virtual Transaction respond(TransactionInterface *transaction);
};

#endif // _BUYER_HPP
