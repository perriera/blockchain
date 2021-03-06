#ifndef _SELLER_HPP
#define _SELLER_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Initiator.hpp"
#include "Responder.hpp"
#include "Transaction.hpp"

interface SellerInterface extends InitiatorInterface with ResponderInterface {
  virtual bool has(const AssetInterface *asset) const pure;
};
class Seller implements SellerInterface {
public:
  virtual Transaction initiate(const AssetInterface &asset);
  virtual Transaction respond(TransactionInterface *transaction);
  virtual bool has(const AssetInterface *asset) const;
  virtual Transaction liquify(const AssetInterface *asset);
  virtual Transaction deposit(const AssetInterface *asset);
  virtual Transaction acquire(const AssetInterface *asset);
  virtual Transaction withdraw(const AssetInterface *asset);
};

#endif // _SELLER_HPP
