#include "common.h"
#include <cassert>
#include <iostream>
#include <sstream>
template <typename T> void printElement(const T &elem) { std::cout << elem; }

void test_printElement() {
  TEST(printElement int, {
    std::stringstream ss;
    auto origcout = std::cout.rdbuf(ss.rdbuf());
    printElement(5);
    std::cout.rdbuf(origcout);
    assert(ss.str() == "5");
  });
  TEST(printElement double, { 
      std::stringstream ss;
      auto origcout = std::cout.rdbuf(ss.rdbuf());
      printElement(5.5);
      std::cout.rdbuf(origcout);
      assert(ss.str() == "5.5"); 
      });
  TEST(printElement string, { 
      std::stringstream ss;
      auto origcout = std::cout.rdbuf(ss.rdbuf());
      printElement(std::string("Hello"));
      std::cout.rdbuf(origcout);
      assert(ss.str() == "Hello"); 
      });
}

int main() {
  test_printElement();
}
