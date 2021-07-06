#ifndef _SERVICES_HPP
#define _SERVICES_HPP

#include <iostream>

#include "../../../extra/include/Definitions.hpp"
#include "../Asset.hpp"

interface ServicesInterface extends AssetInterface{};

class Services implements ServicesInterface {
public:
  virtual std::string say_hello() const;
};

#endif // _SERVICES_HPP
