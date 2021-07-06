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

SCENARIO("Verify Transaction (seller.sell(information))", "[Transaction]") {

  Walmart seller;
  NewsWeekMagazine information;

  REQUIRE(seller.itemsToSell() == 0);
  seller.stock(information);
  seller.stock(information);
  REQUIRE(seller.itemsToSell() == 2);
  seller.sell(information);
  REQUIRE(seller.itemsToSell() == 1);
}

SCENARIO("Verify Transaction (buyer.buy(item))", "[Transaction]") {

  BillGates buyer;
  Walmart seller;
  NewsWeekMagazine information;

  REQUIRE(seller.itemsToSell() == 0);
  seller.stock(information);
  seller.stock(information);
  REQUIRE(seller.itemsToSell() == 2);
  auto item = seller.sell(information);
  REQUIRE(seller.itemsToSell() == 1);
  REQUIRE(buyer.itemsBought() == 0);
  buyer.buy(item);
  REQUIRE(buyer.itemsBought() == 1);
}

// SCENARIO("Verify Transaction (buyer.initiate(information))", "[Transaction]")
// {

//   BillGates buyer;
//   Walmart seller;
//   NewsWeekMagazine information;

//   REQUIRE(seller.itemsToSell() == 0);
//   seller.stock(information);
//   seller.stock(information);
//   REQUIRE(seller.itemsToSell() == 2);
//   Transaction t1 = buyer.initiate(information);
//   Transaction t2 = seller.respond(&t1);
//   REQUIRE(buyer.itemsBought() == 0);
//   REQUIRE(buyer.itemsBought() == 1);
// }
