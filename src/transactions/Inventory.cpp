#include "../../include/transactions/Inventory.hpp"
#include <iostream>

using namespace std;

void Inventory::buy(const Asset &asset) { this->_items.push_back(asset); }

void Inventory::sell(const Asset &asset) {
  AssetList dup;
  this->_items.clear();
  for (auto item : dup) {
    if (item != asset)
      this->_items.push_back(item);
  }
}
