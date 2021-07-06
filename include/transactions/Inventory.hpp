#ifndef _INVENTORY_HPP
#define _INVENTORY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Asset.hpp"
#include "Currency.hpp"
#include "Item.hpp"
#include "Transaction.hpp"

interface InventoryInterface {
  virtual void buy(const Item &item) pure;
  virtual Item sell(const Asset &asset) pure;
};

class Inventory implements InventoryInterface with ItemInterface {
  ItemList _items;

public:
  virtual void buy(const Item &item) { _items.push_back(item); }
  virtual Item sell(const Asset &asset) {
    Item itemSold;
    ItemList newList;
    bool sold = false;
    for (auto _item : _items)
      if (_item == asset && !sold) {
        std::cout << "item sold" << std::endl;
        itemSold = _item;
        sold = true;
      } else
        newList.push_back(_item);
    this->_items = newList;
    if (!sold)
      throw "Item not found in inventory";
    return itemSold;
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
  virtual int itemsToSell() const { return _items.size(); }
  virtual int itemsBought() const { return _items.size(); }
};

#endif // _INVENTORY_HPP
