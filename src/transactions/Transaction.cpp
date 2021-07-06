#include "../../include/transactions/Transaction.hpp"
#include "../../include/transactions/Entity.hpp"
#include "../../include/transactions/Initiator.hpp"
#include "../../include/transactions/Responder.hpp"
#include <iostream>

using namespace std;

void Transaction::provide() {
  auto buyer = reinterpret_cast<Entity *>(_initiator);
  auto seller = reinterpret_cast<Entity *>(_responder);
  auto asset = reinterpret_cast<const Asset *>(this->_asset);
  auto item = seller->sell(*asset);
  buyer->buy(item);
}

void Transaction::consume() {
  _responder->deposit(this->_asset);
  _initiator->withdraw(this->_asset);
}
