#ifndef _CURRENCY_HPP
#define _CURRENCY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "BitCoin.hpp"

interface CurrencyInterface{};

class Currency implements CurrencyInterface with BitCoinInterface {
  friend inline bool operator==(const Currency &a, const Currency &b) {
    return a.value() == b.value();
  }
  friend inline bool operator!=(const Currency &a, const Currency &b) {
    return !(a == b);
  }
  friend inline bool operator>(const Currency &a, const Currency &b) {
    return a.value() > b.value();
  }
  friend inline bool operator<(const Currency &a, const Currency &b) {
    return a.value() < b.value();
  }

  BitCoin _bitCoin;
  float _amount = 0.00;

public:
  Currency(){};
  Currency(float amount) : _amount(amount){};
  virtual float value() const { return _bitCoin.value() * _amount; }
};

#endif // _CURRENCY_HPP
