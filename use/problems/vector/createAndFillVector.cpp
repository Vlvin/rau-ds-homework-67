#include <iostream>
#include <vector>

void createAndFillVector(const int N) {
  std::vector<int> vec(N);
  // vec.reserve(N);
  for (int i = 1; i < N + 1; i++) {
    vec[i - 1] = i;
  }
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "\tsize: " << vec.size() << '\n'
            << "\tcapacity: " << vec.capacity() << std::endl;
}

void test_createAndFillVector() {

  // no way I want to test it using assert
  createAndFillVector(10);
}

int main() { test_createAndFillVector(); }
