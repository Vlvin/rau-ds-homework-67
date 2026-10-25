#include "common.h"
#include <cassert>
#include <cstddef>
#include <iostream>
template <typename T> T sumArray(T *arr, size_t size) {
  T sum = T();
  for (int i = 0; i < size; i++)
    sum += arr[i];
  return sum;
}

void test_sum_array() {
  TEST(sumArray empty, {
    int data[] = {};
    assert(sumArray(data, SARRSIZE(data)) == 0);
  });
  TEST(sumArray int, {
    int data[] = {1, 2, 3, 4, 5};
    // for (int i = 0; i < SARRSIZE(data); i++)
    //   std::cout << data[i] << ' ';
    // std::cout << std::endl;
    assert(sumArray(data, SARRSIZE(data)) == (1 + 2 + 3 + 4 + 5));
  });
  TEST(sumArray double, {
    double data[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    // for (int i = 0; i < SARRSIZE(data); i++)
    //   std::cout << data[i] << ' ';
    // std::cout << std::endl;
    assert(sumArray(data, SARRSIZE(data)) == (1.1 + 2.2 + 3.3 + 4.4 + 5.5));
  });
  TEST(sumArray string, {
    std::string data[] = {"1", "2", "3", "4", "5"};
    // for (int i = 0; i < SARRSIZE(data); i++)
    //   std::cout << data[i] << ' ';
    // std::cout << std::endl;
    assert(sumArray(data, SARRSIZE(data)) == "12345");
  });
}

int main() { test_sum_array(); }
