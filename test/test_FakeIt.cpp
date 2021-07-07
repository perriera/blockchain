#include <fstream>
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <string>   // std::string

#include "../extra/include/ansi_colors.hpp"
#include "../extra/include/crc32_support.hpp"
#include "../extra/include/crc64_support.hpp"
#include "../extra/include/directory.hpp"
#include "../extra/include/string_support.hpp"
#include "../include/HelloWorld.hpp"
#include "catch.hpp"
#include "fakeit.hpp"

struct SomeInterface {
  virtual int foo(int) = 0;
  virtual int bar(int, int) = 0;
};

using namespace std;
using namespace fakeit;

SCENARIO("Verify FakeIt", "[FakeIt]") {

  Mock<SomeInterface> mock;
  // Stub a method to return a value once
  When(Method(mock, foo)).Return(1);

  // Stub multiple return values (The next two lines do exactly the same)
  When(Method(mock, foo)).Return(1, 2, 3);
  When(Method(mock, foo)).Return(1).Return(2).Return(3);

  // Return the same value many times (56 in this example)
  When(Method(mock, foo)).Return(56_Times(1));

  // Return many values many times (First 100 calls will return 1, next 200
  // calls will return 2)
  When(Method(mock, foo)).Return(100_Times(1), 200_Times(2));

  // Always return a value (The next two lines do exactly the same)
  When(Method(mock, foo)).AlwaysReturn(1);
  Method(mock, foo) = 1;
}
