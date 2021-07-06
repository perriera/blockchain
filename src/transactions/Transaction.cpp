#include "../../include/transactions/Transaction.hpp"
#include "../../include/transactions/Initiator.hpp"
#include "../../include/transactions/Responder.hpp"
#include <iostream>

using namespace std;

void Transaction::provide() {
  _responder->liquify(this->_asset);
  _initiator->acquire(this->_asset);
}
void Transaction::consume() {
  _responder->deposit(this->_currency);
  _initiator->withdraw(this->_currency);
}
