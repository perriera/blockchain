#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string>   // std::string

#include "../extra/include/ansi_colors.hpp"
#include "../extra/include/crc32_support.hpp"
#include "../extra/include/crc64_support.hpp"
#include "../extra/include/directory.hpp"
#include "../extra/include/string_support.hpp"
#include "../include/transactions/Buyer.hpp"
#include "../include/transactions/Seller.hpp"
#include "../include/transactions/Transaction.hpp"
#include "../include/transactions/assets/Information.hpp"
#include "../include/transactions/currencies/USD.hpp"

#include "catch.hpp"

using namespace std;

SCENARIO("Verify Transaction", "[Transaction]") {

  Buyer buyer;
  Seller seller;
  Information information;
  USD usd;

  Transaction transaction1 = buyer.initiate(information, usd);
  Transaction transaction2 = seller.respond(&transaction1);
}
