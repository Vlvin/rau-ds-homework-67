

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>
int removeElementsGreaterThan(std::vector<int> &sorted_vec, int limit) {
  int removed = 0;
  while (sorted_vec.size() > 0 && sorted_vec.back() > limit && ++removed)
    sorted_vec.pop_back();
  return removed;
}
void test_removeElementsGreaterThan() {

  { // normal
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> veccpy = vec;
    int removed = removeElementsGreaterThan(vec, 3);
    assert(veccpy == vec);
    assert(std::count_if(vec.begin(), vec.end(),
                         [](int elem) { return elem > 3; }) == 0);
    assert(removed == 2);
  }
  { // empty
    std::vector<int> vec = {};
    std::vector<int> veccpy = vec;
    int removed = removeElementsGreaterThan(vec, 3);
    assert(veccpy == vec);
    assert(vec.size() == 0);
    assert(removed == 0);
  }
  { // remove all
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> veccpy = vec;
    const auto size = vec.size();
    int removed = removeElementsGreaterThan(vec, 0);
    assert(veccpy == vec);
    assert(removed == size);
    assert(vec.size() == 0);
  }
  { // remove none
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> veccpy = vec;
    const auto size = vec.size();
    int removed = removeElementsGreaterThan(vec, INT32_MAX);
    assert(veccpy == vec);
    assert(removed == 0);
    assert(vec.size() == size);
  }
}

int main() {
  test_removeElementsGreaterThan();
}
