#ifndef _INVENTORY_HPP
#define _INVENTORY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Asset.hpp"
#include "Currency.hpp"
#include "Item.hpp"
#include "Transaction.hpp"

interface InventoryInterface {
  virtual void buy(const Asset &asset) pure;
  virtual void sell(const Asset &asset) pure;
};

class Inventory implements InventoryInterface with ItemInterface {
  ItemList _items;

public:
  virtual void buy(const Asset &asset) { throw "Not implemented (yet)"; }
  virtual void sell(const Asset &asset) { throw "Not implemented (yet)"; }
  virtual void buy(const Asset &asset, int count) {
    for (int i = 0; i < count; i++)
      buy(asset);
  }
  virtual long number() const { return -1; }
  virtual Item &stock(const Asset &asset) {
    auto item = Item().stock(asset);
    _items.push_back(item);
    return item;
  }
  virtual void unstock(const Item &item) {
    ItemList newList;
    for (auto _item : _items)
      if (item.number() != _item.number())
        newList.push_back(_item);
    this->_items = newList;
  };
};

#endif // _INVENTORY_HPP
