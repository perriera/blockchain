#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include <iostream>

#include "../../extra/include/Definitions.hpp"
#include "Initiator.hpp"
#include "Responder.hpp"
#include "Transaction.hpp"

interface EntityInterface extends InitiatorInterface with ResponderInterface{};

class Entity implements EntityInterface {
public:
  virtual Transaction initiate(const AssetInterface &asset);
  virtual Transaction respond(TransactionInterface *transaction);
  virtual Transaction liquify(const AssetInterface *asset);
  virtual Transaction deposit(const AssetInterface *asset);
  virtual Transaction acquire(const AssetInterface *asset);
  virtual Transaction withdraw(const AssetInterface *asset);
};

#endif // _ENTITY_HPP
