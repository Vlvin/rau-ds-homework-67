
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
template <class T>
void resizeVector(std::vector<T> &vec, int new_size, const T &default_val) {
  std::cout << "vector before resize" << std::endl;
  for (int i = 0; i < vec.size(); i++) {
    std::cout << '[' << vec[i] << "] ";
  }
  std::cout << std::endl;
  vec.resize(new_size, default_val);
  std::cout << "vector after resize" << std::endl;
  for (int i = 0; i < vec.size(); i++) {
    std::cout << '[' << vec[i] << "] ";
  }
  std::cout << std::endl;
}

void test_resizeVector() {
  { // enlarge
    std::vector<int> vec = {1, 2, 3, 4};
    const auto size = vec.size();
    resizeVector(vec, 10, 10);
    assert(vec.size() == 10);
    assert(std::all_of(vec.begin() + vec.size(), vec.end(),
                       [](int val) { return val == 10; }));
  }
  { // shrink
    std::vector<int> vec = {1, 2, 3, 4};
    const auto size = vec.size();
    resizeVector(vec, 2, 10);
    assert(vec.size() == 2);
  }
  { // NOP
    std::vector<int> vec = {1, 2, 3, 4};
    auto veccpy = vec;
    const auto size = vec.size();
    resizeVector(vec, size, 10);
    assert(vec.size() == size);
    assert(vec == veccpy);
  }
  { // empty
    std::vector<int> vec = {};
    resizeVector(vec, 10, 10);
    assert(vec.size() == 10);
    assert(
        std::all_of(vec.begin(), vec.end(), [](int val) { return val == 10; }));
  }
}

int main() {
  test_resizeVector();
}
