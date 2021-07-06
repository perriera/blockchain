#ifndef _ITEM_HPP
#define _ITEM_HPP

#include <iostream>
#include <vector>

#include "../../extra/include/Definitions.hpp"
#include "Asset.hpp"
#include "Currency.hpp"
#include "Transaction.hpp"

class Item;
interface ItemInterface {
  virtual long number() const pure;
  virtual Item &stock(const Asset &asset, const Currency &cost) pure;
  virtual void unstock(const Item &item) pure;
  virtual int itemsToSell() const pure;
  virtual int itemsBought() const pure;
};

class Item implements ItemInterface {
  friend inline bool operator==(const Item &a, const Item &b) {
    return a._number == b._number;
  }
  friend inline bool operator!=(const Item &a, const Item &b) {
    return !(a == b);
  }
  friend inline bool operator==(const Item &a, const Asset &b) {
    std::string item_a = a._asset;
    std::string item_b = b;
    return item_a == item_b;
  }
  friend inline bool operator!=(const Item &a, const Asset &b) {
    return !(a == b);
  }
  static long _globalNumber;
  long _number = -1;
  Asset _asset;
  Currency _cost;

public:
  Item(){};
  Item(long number, const Asset &asset) : _number(number), _asset(asset){};
  virtual long number() const { return _number; }
  virtual Item &stock(const Asset &asset, const Currency &cost) {
    _number = ++_globalNumber;
    _asset = asset;
    _cost = cost;
    return *this;
  }
  virtual void unstock(const Item &item){};
  virtual int itemsToSell() const { throw "Not implemented"; }
  virtual int itemsBought() const { throw "Not implemented"; }
};

typedef std::vector<Item> ItemList;

#endif // _ITEM_HPP
