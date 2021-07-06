#ifndef _MONEY_HPP
#define _MONEY_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Asset.hpp"

interface MoneyInterface extends AssetInterface{};

class Money implements MoneyInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _MONEY_HPP
