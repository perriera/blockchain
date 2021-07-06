#ifndef _NEWSWEEK_HPP
#define _NEWSWEEK_HPP

#include <iostream>
#include <typeinfo>

#include "../../../../extra/include/Definitions.hpp"
#include "../../currencies/USD.hpp"
#include "../Information.hpp"

class NewsWeekMagazine extends Asset {

public:
  NewsWeekMagazine() : Asset(5.00, USD()) { _details = typeid(*this).name(); }
  operator const std::string &() const { return _details; }
};

#endif // _NEWSWEEK_HPP
