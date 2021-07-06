#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Initiator.hpp"
#include "Inventory.hpp"
#include "Responder.hpp"
#include "Transaction.hpp"

interface EntityInterface extends InitiatorInterface with ResponderInterface
    with InventoryInterface with ItemInterface{};

class Entity implements EntityInterface {
  Inventory _inventory;

public:
  virtual Transaction initiate(const AssetInterface &asset);
  virtual Transaction respond(TransactionInterface *transaction);
  virtual Transaction liquify(const AssetInterface *asset);
  virtual Transaction deposit(const AssetInterface *asset);
  virtual Transaction acquire(const AssetInterface *asset);
  virtual Transaction withdraw(const AssetInterface *asset);
  virtual void buy(const Item &item) { return _inventory.buy(item); }
  virtual Item sell(const Asset &asset) { return _inventory.sell(asset); }
  virtual long number() const { return _inventory.number(); }
  virtual Item &stock(const Asset &asset) { return _inventory.stock(asset); }
  virtual void unstock(const Item &item) { return _inventory.unstock(item); }
  virtual int itemsToSell() const { return _inventory.itemsToSell(); }
  virtual int itemsBought() const { return _inventory.itemsBought(); }
  virtual bool has(const ItemInterface &item) const {
    return _inventory.has(item);
  };
  virtual bool has(const AssetInterface &asset) const {
    return _inventory.has(asset);
  };
  // virtual InitiatorInterface *initiator() { return _initiator; }
  // virtual ResponderInterface *responder() { return _responder; }
};

#endif // _ENTITY_HPP
