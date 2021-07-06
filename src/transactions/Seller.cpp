#include "../../include/transactions/Seller.hpp"
#include "../../include/transactions/Asset.hpp"
#include <iostream>

using namespace std;

Transaction Seller::initiate(const AssetInterface &asset) {}

Transaction Seller::respond(TransactionInterface *transaction) {
  transaction->setResponder(this);
  if (this->has(transaction->asset())) {
    transaction->provide();
    transaction->consume();
  }
}

bool Seller::has(const AssetInterface *asset) const { return true; }

Transaction Seller::liquify(const AssetInterface *asset) {
  return Transaction();
}
Transaction Seller::deposit(const AssetInterface *asset) {
  return Transaction();
}
Transaction Seller::acquire(const AssetInterface *asset) {
  return Transaction();
}
Transaction Seller::withdraw(const AssetInterface *asset) {
  return Transaction();
}
