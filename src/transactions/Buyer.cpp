#include "../../include/transactions/Buyer.hpp"
#include <iostream>

using namespace std;

Transaction Buyer::initiate(const AssetInterface &asset,
                            const CurrencyInterface &currency) {
  Transaction transaction;
  transaction.setInitiator(this);
  transaction.set(&asset);
  transaction.set(&currency);
  return transaction;
}

Transaction Buyer::respond(TransactionInterface *transaction) {}

Transaction Buyer::liquify(const AssetInterface *asset) {
  return Transaction();
}
Transaction Buyer::deposit(const CurrencyInterface *currency) {
  return Transaction();
}
Transaction Buyer::acquire(const AssetInterface *asset) {
  return Transaction();
}
Transaction Buyer::withdraw(const CurrencyInterface *currency) {
  return Transaction();
}
