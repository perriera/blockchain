#ifndef _INITIATOR_HPP
#define _INITIATOR_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Asset.hpp"
#include "Currency.hpp"
#include "Transaction.hpp"

interface InitiatorInterface {
  virtual Transaction initiate(const AssetInterface &asset,
                               const CurrencyInterface &money) pure;
  virtual Transaction acquire(const AssetInterface *asset) pure;
  virtual Transaction withdraw(const CurrencyInterface *currency) pure;
};

#endif // _INITIATOR_HPP
