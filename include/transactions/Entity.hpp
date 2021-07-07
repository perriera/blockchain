#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Currency.hpp"
#include "Initiator.hpp"
#include "Inventory.hpp"
#include "Responder.hpp"
#include "Transaction.hpp"

interface ExchangeInterface {
  virtual float networth() pure;
  virtual float deposit(const Currency &amount) pure;
  virtual float withdrawal(const Currency &amount) pure;
};

interface EntityInterface extends InitiatorInterface with ResponderInterface
    with InventoryInterface with ItemInterface with ExchangeInterface{};

class Entity implements EntityInterface {
  float _money = 0.00;
  Inventory _inventory;

public:
  virtual Transaction initiate(const AssetInterface &asset);
  virtual Transaction respond(TransactionInterface *transaction);
  virtual Transaction liquify(const AssetInterface *asset);
  virtual Transaction deposit(const AssetInterface *asset);
  virtual Transaction acquire(const AssetInterface *asset);
  virtual Transaction withdraw(const AssetInterface *asset);
  virtual void buy(const Item &item, const Currency &currency) {
    return _inventory.buy(item, currency);
  }
  virtual Item sell(const Asset &asset, const Currency &currency) {
    return _inventory.sell(asset, currency);
  }
  virtual long number() const { return _inventory.number(); }
  virtual Item &stock(const Asset &asset, const Currency &cost) {
    return _inventory.stock(asset, cost);
  }
  virtual void unstock(const Item &item) { return _inventory.unstock(item); }
  virtual int itemsToSell() const { return _inventory.itemsToSell(); }
  virtual int itemsBought() const { return _inventory.itemsBought(); }
  virtual bool has(const ItemInterface &item) const {
    return _inventory.has(item);
  };
  virtual bool has(const AssetInterface &asset) const {
    return _inventory.has(asset);
  };
  virtual float cost() const { throw "Not implemented"; };
  virtual float price() const { throw "Not implemented"; };
  virtual float deposit(const Currency &amount) {
    _money += amount.value();
    return _money;
  };
  virtual float withdrawal(const Currency &amount) {
    _money -= amount.value();
    return _money;
  };
  virtual float networth() { return _money; };
};

#endif // _ENTITY_HPP
