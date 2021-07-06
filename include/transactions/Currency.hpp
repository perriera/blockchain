#ifndef _CURRENCY_HPP
#define _CURRENCY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "BitCoin.hpp"

interface CurrencyInterface{};

class Currency implements CurrencyInterface with BitCoinInterface {
  BitCoin _bitCoin;

public:
  virtual float value() const { return _bitCoin.value(); }
};

#endif // _CURRENCY_HPP
