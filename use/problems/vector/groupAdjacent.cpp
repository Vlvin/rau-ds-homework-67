

#include <cassert>
#include <vector>
std::vector<std::vector<int>> groupAdjacent(const std::vector<int> &vec) {
  std::vector<std::vector<int>> result;
  for (int i = 0; i < vec.size(); i++) {
    if (i == 0 || vec[i] != vec[i - 1])
      result.push_back({});
    result.back().push_back(vec[i]);
  }
  return result;
}

void test_groupAdjacent() {
  { // normal
    std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};
    auto res = groupAdjacent(vec);
    assert(res ==
           std::vector<std::vector<int>>({{1, 1}, {2, 2, 2}, {3}, {1, 1}}));
  }
  { // empty
    std::vector<int> vec = {};
    auto res = groupAdjacent(vec);
    assert(res.size() == 0);
  }
}

int main() {}
