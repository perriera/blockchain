#include "../../include/transactions/Entity.hpp"
#include <iostream>

using namespace std;

Transaction Entity::initiate(const AssetInterface &asset) {
  Transaction transaction;
  transaction.setInitiator(this);
  transaction.set(&asset);
  return transaction;
}

Transaction Entity::respond(TransactionInterface *transaction) {}

Transaction Entity::liquify(const AssetInterface *asset) {
  return Transaction();
}
Transaction Entity::deposit(const AssetInterface *asset) {
  return Transaction();
}
Transaction Entity::acquire(const AssetInterface *asset) {
  return Transaction();
}
Transaction Entity::withdraw(const AssetInterface *asset) {
  return Transaction();
}
