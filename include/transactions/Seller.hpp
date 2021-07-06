#ifndef _SELLER_HPP
#define _SELLER_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Initiator.hpp"
#include "Responder.hpp"
#include "Transaction.hpp"

interface SellerInterface extends InitiatorInterface with ResponderInterface {
  virtual std::string say_hello() const pure;
  virtual bool has(const AssetInterface *asset) const pure;
};
class Seller implements SellerInterface {
public:
  virtual std::string say_hello() const;
  virtual Transaction initiate(const AssetInterface &asset,
                               const CurrencyInterface &money);
  virtual Transaction respond(TransactionInterface *transaction);
  virtual bool has(const AssetInterface *asset) const;
};

#endif // _SELLER_HPP
