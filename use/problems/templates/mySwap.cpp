#include "common.h"
#include <cassert>
#include <iostream>
template <typename T> void mySwap(T &l, T &r) {
  T temp = std::move(l);
  l = std::move(r);
  r = std::move(temp);
}

void test_mySwap() {
  TEST(mySwap int, {
    int a = 5, b = 10;
    mySwap(a, b);
    assert(a == 10 && b == 5);
  });
  TEST(mySwap double, {
    double a = 5.5, b = 10.10;
    mySwap(a, b);
    // pray that it'll compare doubles normally
    assert(a == 10.10 && b == 5.5);
  });
  TEST(mySwap string, {
    std::string a = "5", b = "10";
    mySwap(a, b);
    assert(a == "10" && b == "5");
  });
}

int main() {
  test_mySwap();
}
