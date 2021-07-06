#include "../../include/transactions/Buyer.hpp"
#include <iostream>

using namespace std;

string Buyer::say_hello() const { return "Hello, world"; }

Transaction Buyer::initiate(const AssetInterface &asset,
                            const CurrencyInterface &currency) {
  Transaction transaction;
  transaction.setInitiator(this);
  transaction.set(&asset);
  transaction.set(&currency);
  return transaction;
}

Transaction Buyer::respond(TransactionInterface *transaction) {}
