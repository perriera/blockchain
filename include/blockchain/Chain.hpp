#ifndef _CHAIN_HPP
#define _CHAIN_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"

interface ChainInterface {
  virtual std::string say_hello() const pure;
};

class Chain implements ChainInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _CHAIN_HPP
