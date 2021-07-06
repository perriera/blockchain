#ifndef _INITIATOR_HPP
#define _INITIATOR_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Asset.hpp"
#include "Money.hpp"
#include "Transaction.hpp"

interface InitiatorInterface {
  virtual Transaction initiate(const AssetInterface &asset,
                               const MoneyInterface &money) const pure;
};

#endif // _INITIATOR_HPP
