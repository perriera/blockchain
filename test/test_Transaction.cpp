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
#include "../include/transactions/assets/examples/NewsWeek.hpp"
#include "../include/transactions/currencies/USD.hpp"
#include "../include/transactions/entities/BillGates.hpp"
#include "../include/transactions/entities/Walmart.hpp"

#include "catch.hpp"

using namespace std;

SCENARIO("Verify Transaction", "[Transaction]") {

  BillGates buyer;
  Walmart seller;
  NewsWeekMagazine information;

  Transaction transaction1 = buyer.initiate(information);
  Transaction transaction2 = seller.respond(&transaction1);
}
