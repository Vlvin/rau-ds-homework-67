

#include "common.h"
#include <cassert>
#include <cstring>
template <typename T> bool isEqual(T left, T right) { return left == right; }
template <> bool isEqual(char *left, char *right) {
  return std::strcmp(left, right) == 0;
}

void test_isEqual() {
  TEST(isEqual int, {
    assert(isEqual(5, 5));
    assert(!isEqual(6, 7));
  });
  TEST(isEqual double, {
    assert(isEqual(5.5, 5.5));
    assert(!isEqual(1.3, 3.7));
  });
  TEST(isEqual char*, {
    assert(isEqual("7", "7"));
    assert(!isEqual("Hello", "World"));
  });
}

int main() {
  test_isEqual();
}
