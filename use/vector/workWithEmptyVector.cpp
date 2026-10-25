
#include <iostream>
#include <vector>
void workWithEmptyVector() {
  std::vector<int> vec;
  for (int i = 1; i < 11; i++) {
    vec.push_back(i);
    std::cout << vec.size() << '\t' << vec.capacity() << std::endl;
  }
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

void test_workWithEmptyVector() {
  // No way I will test it with assert
  workWithEmptyVector();
}

int main() { test_workWithEmptyVector(); }
