#ifndef _NEWSWEEK_HPP
#define _NEWSWEEK_HPP

#include <iostream>

#include "../../../../extra/include/Definitions.hpp"
#include "../../currencies/USD.hpp"
#include "../Information.hpp"

class NewsWeekMagazine extends Asset {
  const float _cost = 5.00;
  const USD _inUSD;

public:
  NewsWeekMagazine() : Asset(_cost, _inUSD) {}
};

#endif // _NEWSWEEK_HPP
