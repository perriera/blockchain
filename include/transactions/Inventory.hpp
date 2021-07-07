#ifndef _INVENTORY_HPP
#define _INVENTORY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Asset.hpp"
#include "Currency.hpp"
#include "Item.hpp"
#include "Transaction.hpp"

interface HasInterface {
  virtual bool has(const ItemInterface &item) const pure;
  virtual bool has(const AssetInterface &asset) const pure;
};

interface InventoryInterface extends HasInterface {
  virtual void buy(const Item &item, const Currency &currency) pure;
  virtual Item sell(const Asset &asset, const Currency &currency) pure;
};

class Inventory implements InventoryInterface with ItemInterface {
  ItemList _items;

public:
  virtual void buy(const Item &item, const Currency &currency) {
    _items.push_back(item);
  }
  virtual Item sell(const Asset &asset, const Currency &currency) {
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
  virtual Item &stock(const Asset &asset, const Currency &cost) {
    auto item = Item().stock(asset, cost);
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
  virtual bool has(const ItemInterface &item) const {
    for (auto _item : _items)
      if (_item == reinterpret_cast<const Item &>(item))
        return true;
    return false;
  };
  virtual bool has(const AssetInterface &asset) const {
    for (auto _item : _items)
      if (_item == reinterpret_cast<const Asset &>(asset))
        return true;
    return false;
  };
};

#endif // _INVENTORY_HPP
