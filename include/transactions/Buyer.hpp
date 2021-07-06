#ifndef _BUYER_HPP
#define _BUYER_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Initiator.hpp"
#include "Responder.hpp"
#include "Transaction.hpp"

interface BuyerInterface extends InitiatorInterface with ResponderInterface{};

class Buyer implements BuyerInterface {
public:
  virtual Transaction initiate(const AssetInterface &asset,
                               const CurrencyInterface &currency);
  virtual Transaction respond(TransactionInterface *transaction);
  virtual Transaction liquify(const AssetInterface *asset);
  virtual Transaction deposit(const CurrencyInterface *currency);
  virtual Transaction acquire(const AssetInterface *asset);
  virtual Transaction withdraw(const CurrencyInterface *currency);
};

#endif // _BUYER_HPP
