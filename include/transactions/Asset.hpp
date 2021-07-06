#ifndef _ASSET_HPP
#define _ASSET_HPP

#include <iostream>
#include <vector>

#include "../../extra/include/Definitions.hpp"
#include "Currency.hpp"

interface AssetInterface {
  virtual float cost() const pure;
  virtual const CurrencyInterface &currency() const pure;
};

class Asset implements AssetInterface {
  float _cost = 5.00;
  const CurrencyInterface &_currency;

public:
  Asset(const float cost, const CurrencyInterface &currency)
      : _cost(cost), _currency(currency){};
  virtual float cost() const { return _cost; };
  virtual const CurrencyInterface &currency() const { return _currency; };
};

typedef std::vector<Asset> AssetList;

#endif // _ASSET_HPP
