#ifndef _GOODS_HPP
#define _GOODS_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Asset.hpp"

interface GoodsInterface extends AssetInterface{};

class Goods implements GoodsInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _GOODS_HPP
