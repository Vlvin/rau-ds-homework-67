
#include <cassert>
#include <iostream>
#include <vector>
void manageCapacity(std::vector<int> &vec) {
  std::cout << vec.size() << "\t" << vec.capacity() << std::endl;
  vec.reserve(vec.size() + 500);
  for (int i = 1; i < 500 + 1; i++)
    vec.push_back(i);
  std::cout << vec.size() << "\t" << vec.capacity() << std::endl;
}

void test_manageCapacity() {
 { // empty vector
   std::vector<int> vec;
   manageCapacity(vec);
   assert(vec.size() == 500);
   assert(vec.capacity() == 500);
 }
 { // non empty vector
   std::vector<int> vec;
   const auto size = vec.size();
   manageCapacity(vec);
   assert(vec.size() == size+500);
   assert(vec.capacity() == size+500);
 }
}

int main() {
  test_manageCapacity();
}

