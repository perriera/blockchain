#ifndef _ASSET_HPP
#define _ASSET_HPP

#include <iostream>
#include <vector>

#include "../../extra/include/Definitions.hpp"
#include "Currency.hpp"
#include "currencies/USD.hpp"

interface AssetInterface {
  virtual float cost() const pure;
  virtual const CurrencyInterface &currency() const pure;
};

class Asset implements AssetInterface {
  friend inline bool operator==(const Asset &a, const Asset &b) {
    return a._cost == b._cost;
  }
  friend inline bool operator!=(const Asset &a, const Asset &b) {
    return !(a == b);
  }
  float _cost;
  Currency _currency;

public:
  Asset() : _cost(0.00) {}
  Asset(const float cost, const Currency &currency)
      : _cost(cost), _currency(currency){};
  virtual float cost() const { return _cost; };
  virtual const CurrencyInterface &currency() const { return _currency; };
};

typedef std::vector<Asset> AssetList;

#endif // _ASSET_HPP
