

#include <cstddef>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
auto generateBinaryNumbers(const size_t N) {
  std::queue<std::string> nums;
  for (int i = 1; i <= N; i++) {
    std::stack<char> num = {};
    for (int j = i; j > 0; j /= 2) {
      num.push(j % 2 + '0');
    }
    std::string num_s = "";
    while (num.size() != 0) {
      num_s.push_back(num.top());
      num.pop();
    }
    nums.push(num_s);
  }
  return nums;
}

void test_generateBinaryNumbers() {
  { // normal
    auto nums = generateBinaryNumbers((10));
    while (nums.size() != 0) {
      std::cout << nums.front() << std::endl;
      nums.pop();
    }
  }
}

int main() { test_generateBinaryNumbers(); }
