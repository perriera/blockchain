#include "../../include/transactions/Seller.hpp"
#include <iostream>

using namespace std;

string Seller::say_hello() const { return "Hello, world"; }

Transaction Seller::initiate(const AssetInterface &asset,
                             const CurrencyInterface &money) {}

Transaction Seller::respond(TransactionInterface *transaction) {
  std::cout << "hello, jesus" << std::endl;
  auto asset = transaction->asset();

  if (this->has(transaction->asset()))
    transaction->provide();
}

bool Seller::has(const AssetInterface *asset) const { return true; }
