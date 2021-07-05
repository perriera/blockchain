#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string>   // std::string

#include "../extra/include/ansi_colors.hpp"
#include "../extra/include/crc32_support.hpp"
#include "../extra/include/crc64_support.hpp"
#include "../extra/include/directory.hpp"
#include "../extra/include/string_support.hpp"
#include "../include/blockchain/Chain.hpp"
#include "catch.hpp"

using namespace std;

SCENARIO("Verify Chain", "[Chain]") {

  Chain chain;
  REQUIRE(chain.say_hello() == "Hello, world");
}
