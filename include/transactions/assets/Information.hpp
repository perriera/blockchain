#ifndef _INFORMATION_HPP
#define _INFORMATION_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Asset.hpp"

interface InformationInterface extends AssetInterface{};

class Information implements InformationInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _INFORMATION_HPP
