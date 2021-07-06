#ifndef _ITEM_HPP
#define _ITEM_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Asset.hpp"
#include "Currency.hpp"
#include "Transaction.hpp"

interface ItemInterface {
  virtual long number() const pure;
  virtual void stock(const Asset &asset) pure;
  virtual void unstock(const Asset &asset) pure;
};

class Item implements ItemInterface {
  static long _globalNumber;
  long _number;
  Asset _asset;

public:
  Item();
  Item(long number, const Asset &asset) : _number(number), _asset(asset){};
  virtual long number() const { return _number; }
  virtual void stock(const Asset &asset) {
    _number = ++_globalNumber;
    // _asset = asset;
  }
  virtual void unstock(const Asset &asset) pure;
};

#endif // _ITEM_HPP