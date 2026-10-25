

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
std::vector<int> createVectorFromInput() {
  std::vector<int> vec;
  int num;
  while ((std::cin >> num, num != 0)) {
    vec.push_back(num);
  }
  return vec;
}

void test_createVectorFromInput() {
  auto vec = createVectorFromInput();
  assert(std::count(vec.begin(), vec.end(), 0) == 0);
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  test_createVectorFromInput();
}
