#ifndef _INVENTORY_HPP
#define _INVENTORY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Asset.hpp"
#include "Currency.hpp"
#include "Transaction.hpp"

interface InventoryInterface {
  virtual void buy(const Asset &asset) pure;
  virtual void sell(const Asset &asset) pure;
};

class Inventory implements InventoryInterface {
  AssetList _items;

public:
  virtual void buy(const Asset &asset);
  virtual void sell(const Asset &asset);
  virtual void buy(const Asset &asset, int count) {
    for (int i = 0; i < count; i++)
      buy(asset);
  }
};

#endif // _INVENTORY_HPP
