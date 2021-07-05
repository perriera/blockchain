#ifndef _BLOCK_HPP
#define _BLOCK_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"

interface BlockInterface {
  virtual std::string say_hello() const pure;
};

class Block implements BlockInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _BLOCK_HPP
