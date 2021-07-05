#ifndef _ASSET_HPP
#define _ASSET_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"

interface AssetInterface {
  virtual std::string say_hello() const pure;
};

class Asset implements AssetInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _ASSET_HPP
