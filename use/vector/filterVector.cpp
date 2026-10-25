

#include <cassert>
#include <vector>
template <typename T>
std::vector<T> filterVector(const std::vector<T> &vec,
                            bool (*pred)(const T &)) {
  std::vector<T> result;
  result.reserve(vec.size());
  for (int i = 0; i < vec.size(); i++) {
    if (pred(vec[i]))
      result.push_back(vec[i]);
  }
  return result;
}

bool isEven(const int &val) { return val % 2 == 0; }

void test_filterVector() {
  { // filter normal vec
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    auto res = filterVector(vec, isEven);
    assert(vec == std::vector<int>({2, 4, 6}));
  }
  { // filter empty vec
    std::vector<int> vec = {};
    auto filtered = filterVector(vec, isEven);
    assert(filtered.size() == 0);
  }
  { // filter filtered vec
    std::vector<int> vec = {2, 4, 6};
    auto filtered = filterVector(vec, isEven);
    assert(filtered == std::vector<int>({2, 4, 6}));
  }
  { // filter whole vector out
    std::vector<int> vec = {1, 3, 5, 7, 9};
    auto filtered = filterVector(vec, isEven);
    assert(filtered.size() == 0);
  }
}

int main() {
  test_filterVector();
}
