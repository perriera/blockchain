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
  seller.stock(information, USD(5));
  seller.stock(information, USD(5));
  REQUIRE(seller.itemsToSell() == 2);
  seller.sell(information, USD(7));
  REQUIRE(seller.itemsToSell() == 1);
}

SCENARIO("Verify Transaction (buyer.buy(item))", "[Transaction]") {

  BillGates buyer;
  Walmart seller;
  NewsWeekMagazine information;

  REQUIRE(seller.itemsToSell() == 0);
  seller.stock(information, USD(5));
  seller.stock(information, USD(5));
  REQUIRE(seller.itemsToSell() == 2);
  auto item = seller.sell(information, USD(7));
  REQUIRE(seller.itemsToSell() == 1);
  REQUIRE(buyer.itemsBought() == 0);
  buyer.buy(item, USD(7));
  REQUIRE(buyer.itemsBought() == 1);
}

SCENARIO("Verify Transaction (widthdrawl/deposit)", "[Transaction]") {

  BillGates buyer;
  Walmart seller;

  REQUIRE(seller.networth() == 0.00);
  REQUIRE(seller.networth() == 0.00);
  seller.deposit(USD(7));
  buyer.withdrawal(USD(7));
  REQUIRE(seller.networth() == USD(7));
  REQUIRE(buyer.networth() == -USD(7));
}

SCENARIO("Verify Transaction (buyer.buy(item)) throws", "[Transaction]") {

  BillGates buyer;
  Walmart seller;
  NewsWeekMagazine information;

  REQUIRE(seller.itemsToSell() == 0);
  seller.stock(information, USD(5));
  seller.stock(information, USD(5));
  REQUIRE(seller.itemsToSell() == 2);
  auto item = seller.sell(information, USD(7));
  REQUIRE(seller.itemsToSell() == 1);
  REQUIRE(buyer.itemsBought() == 0);
  try {
    buyer.buy(item, USD(1));
  } catch (const char *ex) {
    // cout << ex << endl;
  }
  REQUIRE(buyer.itemsBought() == 0);
}

SCENARIO("Verify Transaction (buyer.initiate(item)) throws", "[Transaction]") {

  BillGates buyer;
  Walmart seller;
  NewsWeekMagazine information;

  buyer.deposit(USD(20));
  REQUIRE(buyer.networth() == USD(20));
  REQUIRE(seller.networth() == USD(0));
  REQUIRE(buyer.itemsBought() == 0);
  REQUIRE(seller.itemsToSell() == 0);
  seller.stock(information, USD(5));
  seller.stock(information, USD(5));
  REQUIRE(seller.itemsToSell() == 2);

  auto t1 = buyer.initiate(information);
  auto t2 = seller.respond(&t1);
  // REQUIRE(seller.itemsToSell() == 1);
  // REQUIRE(buyer.itemsBought() == 1);
  // REQUIRE(buyer.networth() == USD(15));
  // REQUIRE(seller.networth() == USD(5));
}