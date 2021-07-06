#ifndef _ASSET_HPP
#define _ASSET_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Currency.hpp"

interface AssetInterface {
  virtual float cost() const pure;
  virtual const CurrencyInterface &currency() const pure;
};

#endif // _ASSET_HPP
