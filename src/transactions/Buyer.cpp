#include "../../include/transactions/Buyer.hpp"
#include <iostream>

using namespace std;

Transaction Buyer::initiate(const AssetInterface &asset) {
  Transaction transaction;
  transaction.setInitiator(this);
  transaction.set(&asset);
  return transaction;
}

Transaction Buyer::respond(TransactionInterface *transaction) {}

Transaction Buyer::liquify(const AssetInterface *asset) {
  return Transaction();
}
Transaction Buyer::deposit(const AssetInterface *asset) {
  return Transaction();
}
Transaction Buyer::acquire(const AssetInterface *asset) {
  return Transaction();
}
Transaction Buyer::withdraw(const AssetInterface *asset) {
  return Transaction();
}
