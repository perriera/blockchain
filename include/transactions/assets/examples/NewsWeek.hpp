#ifndef _NEWSWEEK_HPP
#define _NEWSWEEK_HPP

#include <iostream>

#include "../../../../extra/include/Definitions.hpp"
#include "../../currencies/USD.hpp"
#include "../Information.hpp"

class NewsWeekMagazine implements InformationInterface {
  float _cost = 5.00;
  USD _inUSD;

public:
  virtual float cost() const { return _cost; };
  virtual const CurrencyInterface &currency() const { return _inUSD; };
};

#endif // _NEWSWEEK_HPP
