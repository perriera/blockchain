#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Initiator.hpp"
#include "Inventory.hpp"
#include "Responder.hpp"
#include "Transaction.hpp"

interface EntityInterface extends InitiatorInterface with ResponderInterface
    with InventoryInterface{};

class Entity implements EntityInterface {
  Inventory _inventory;

public:
  virtual Transaction initiate(const AssetInterface &asset);
  virtual Transaction respond(TransactionInterface *transaction);
  virtual Transaction liquify(const AssetInterface *asset);
  virtual Transaction deposit(const AssetInterface *asset);
  virtual Transaction acquire(const AssetInterface *asset);
  virtual Transaction withdraw(const AssetInterface *asset);
  virtual void buy(const Asset &asset) { return _inventory.buy(asset); }
  virtual void sell(const Asset &asset) { return _inventory.sell(asset); }
  virtual void buy(const Asset &asset, int count) {
    return _inventory.buy(asset, count);
  }
};

#endif // _ENTITY_HPP
