
#include <cassert>
#include <vector>
std::vector<int> mergeSortedVectors(const std::vector<int> &vec_a,
                                    const std::vector<int> &vec_b) {
  std::vector<int> result;
  result.reserve(vec_a.size() + vec_b.size());
  int i = 0, j = 0;
  while (i < vec_a.size() && j < vec_b.size())
    if (vec_a[i] < vec_b[i])
      result.push_back(std::move(vec_a[i++]));
    else
      result.push_back(std::move(vec_b[j++]));
  while (i < vec_a.size())
    result.push_back(std::move(vec_a[i++]));
  while (j < vec_b.size())
    result.push_back(std::move(vec_b[j++]));
  return std::move(result);
}

void test_mergeSortedVectors() {
  { // normal
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {1, 2};
    auto ab = mergeSortedVectors(a, b);
    assert(ab == std::vector<int>({1, 1, 2, 2, 3}));
  }
  { // a is empty
    std::vector<int> a = {};
    std::vector<int> b = {1, 2};
    auto ab = mergeSortedVectors(a, b);
    assert(ab == b);
  }
  { // b is empty
    std::vector<int> a = {1,2,3};
    std::vector<int> b = {};
    auto ab = mergeSortedVectors(a, b);
    assert(ab == a);
  }
  { // a and b are empty
    std::vector<int> a = {};
    std::vector<int> b = {};
    auto ab = mergeSortedVectors(a, b);
    assert(ab == a);
  }
}

int main() {
  test_mergeSortedVectors();
}
