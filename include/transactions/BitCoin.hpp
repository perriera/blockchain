#ifndef _BITCOIN_HPP
#define _BITCOIN_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"

interface BitCoinInterface {
  virtual float value() const pure;
};

class BitCoin implements BitCoinInterface {
  float _value = 1.00;

public:
  virtual float value() const { return _value; }
};

#endif // _BITCOIN_HPP
