#ifndef _NEWSWEEK_HPP
#define _NEWSWEEK_HPP

#include <iostream>

#include "../../../../extra/include/Definitions.hpp"
#include "../../currencies/USD.hpp"
#include "../Information.hpp"

class NewsWeekMagazine extends Asset {
  std::string _details = "Your very own copy of NewsWeekMagazine";

public:
  NewsWeekMagazine() : Asset(5.00, USD()) {}
};

#endif // _NEWSWEEK_HPP
