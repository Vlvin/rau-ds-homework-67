#include "common.h"
#include <cassert>
#include <iostream>
#include <ostream>
#include <sstream>

template <typename T1, typename T2> class Pair {

public:
  Pair(const T1 &first = T1(), const T2 &second = T2())
      : first(first), second(second) {}
  friend std::ostream &operator<<(std::ostream &os, Pair<T1, T2> &pair) {
    os << "Pair(" << pair.first << ";" << pair.second << ")";
    return os;
  }

  T1 first;
  T2 second;
};

void test_Pair() {
  TEST(Pair<int; int>, {
    Pair<int, int> pair(6, 7);
    std::stringstream opair;
    opair << pair;
    assert(opair.str() == "Pair(6;7)");
  });
  TEST(Pair<double; double>, {
    Pair<double, double> pair(6.6, 7.7);
    std::stringstream opair;
    opair << pair;
    assert(opair.str() == "Pair(6.6;7.7)");
  });
  TEST(Pair<string; string>, {
    Pair<std::string, std::string> pair("hello", "world");
    std::stringstream opair;
    opair << pair;
    assert(opair.str() == "Pair(hello;world)");
  });
}

int main() {
  test_Pair();
}
