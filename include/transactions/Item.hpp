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
  virtual Item &stock(const Asset &asset) pure;
  virtual void unstock(const Item &item) pure;
};

class Item implements ItemInterface {
  static long _globalNumber;
  long _number = -1;
  Asset _asset;

public:
  Item(){};
  Item(long number, const Asset &asset) : _number(number), _asset(asset){};
  virtual long number() const { return _number; }
  virtual Item &stock(const Asset &asset) {
    _number = ++_globalNumber;
    _asset = asset;
    return *this;
  }
  virtual void unstock(const Item &item){};
};

typedef std::vector<Item> ItemList;

#endif // _ITEM_HPP
