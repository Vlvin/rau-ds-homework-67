#include "common.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
size_t linearSearch(const std::vector<T> &list, const T &val) {
  for (int i = 0; i < list.size(); i++)
    if (list[i] == val)
      return i;
  return -1;
}

void test_linearSearch() {
  TEST(linearSearch int, {
    std::vector<int> data = {1, 2, 3, 4, 5};
    assert(linearSearch(data, 3) == 2);
    assert(linearSearch(data, 7) == -1);
  });
  TEST(linearSearch double, {
    std::vector<double> data = {1.1, 2.2, 3.3, 4.4, 5.5};
    assert(linearSearch(data, 3.3) == 2);
    assert(linearSearch(data, 7.7) == -1);
  });
  TEST(linearSearch string, {
    std::vector<std::string> data = {"1.1", "2.2", "3.3", "4.4", "5.5"};
    assert(linearSearch(data, std::string("3.3")) == 2);
    assert(linearSearch(data, std::string("7.7")) == -1);
  });
}

int main() { test_linearSearch(); }
