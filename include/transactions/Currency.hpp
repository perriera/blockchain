#ifndef _CURRENCY_HPP
#define _CURRENCY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "BitCoin.hpp"

interface CurrencyInterface{};

class Currency implements CurrencyInterface with BitCoinInterface {
  BitCoin _bitCoin;
  float _amount = 0.00;

public:
  Currency(){};
  Currency(float amount) : _amount(amount){};
  virtual float value() const { return _bitCoin.value() * _amount; }
  operator float() const { return value(); }
};

#endif // _CURRENCY_HPP
