

#include "common.h"
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>
template <typename T, size_t N> class FixedArray {
public:
  FixedArray() {}
  FixedArray(const std::initializer_list<T> &list) {
    int i = 0;
    for (auto &elem : list) {
      validate(i);
      data[i] = elem;
      i++;
    }
  }
  void set(int index, const T &value) {
    validate(index);
    data[index] = value;
  }
  T &get(int index) {
    validate(index);
    return data[index];
  }
  constexpr size_t size() { return N; }

private:
  void validate(int index) {
    if (index < 0 || N <= index)
      throw std::invalid_argument("Array has size " + std::to_string(N));
  }
  T data[N];
};

void test_FixedArray() {
  TEST(FixedArray int, {
    FixedArray<int, 5> fa;
    for (int i = 0; i < fa.size(); i++)
      fa.set(i, i);
    for (int i = 0; i < fa.size(); i++)
      assert(fa.get(i) == i);
  });
  TEST(FixedArray double, {
    FixedArray<double, 5> fa;
    for (int i = 0; i < fa.size(); i++)
      fa.set(i, (double)i);
    for (int i = 0; i < fa.size(); i++)
      assert(fa.get(i) == (double)i);
  });
  TEST(FixedArray string, {
    FixedArray<std::string, 5> fa;
    for (int i = 0; i < fa.size(); i++)
      fa.set(i, std::to_string(i));
    for (int i = 0; i < fa.size(); i++)
      assert(fa.get(i) == std::to_string(i));
  });
}

int main() {
  test_FixedArray();
}
