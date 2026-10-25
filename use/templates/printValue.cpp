

#include "common.h"
#include <cassert>
#include <iostream>
#include <sstream>
template <typename T> void printValue(T val) { std::cout << val; }

template <> void printValue(bool val) { std::cout << (val ? "true" : "false"); }
template <> void printValue(char *val) { std::cout << '[' << val << ']'; }

void test_printValue() {
  TEST(printValue int, {
    std::stringstream ss;
    auto origcout = std::cout.rdbuf(ss.rdbuf());
    int val = 12;
    printValue(val);
    std::cout.rdbuf(origcout);
    assert(ss.str() == "12");
  });
  TEST(printValue bool true, {
    std::stringstream ss;
    auto origcout = std::cout.rdbuf(ss.rdbuf());
    bool val = true;
    printValue(val);
    std::cout.rdbuf(origcout);
    assert(ss.str() == "true");
  });
  TEST(printValue bool false, {
    std::stringstream ss;
    auto origcout = std::cout.rdbuf(ss.rdbuf());
    bool val = false;
    printValue(val);
    std::cout.rdbuf(origcout);
    assert(ss.str() == "false");
  });
  TEST(printValue const char*, {
    std::stringstream ss;
    auto origcout = std::cout.rdbuf(ss.rdbuf());
    char val[] = "Hello";
    printValue(val);
    std::cout.rdbuf(origcout);
    assert(ss.str() == "[Hello]");
  });
}

int main() {
  test_printValue();
}
