#include "../../include/transactions/Seller.hpp"
#include <iostream>

using namespace std;

Transaction Seller::initiate(const AssetInterface &asset,
                             const CurrencyInterface &money) {}

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
Transaction Seller::deposit(const CurrencyInterface *currency) {
  return Transaction();
}
Transaction Seller::acquire(const AssetInterface *asset) {
  return Transaction();
}
Transaction Seller::withdraw(const CurrencyInterface *currency) {
  return Transaction();
}
