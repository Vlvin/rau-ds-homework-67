#include "ForwardList.h"
#include <cassert>
#include <iostream>

// Реализуйте методы ForwardList<T>:
//   1. ForwardList()                   - конструктор
//   2. ~ForwardList()                  - деструктор
//   3. ForwardList(const &)            - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push_front(const T&)            - добавить в начало
//   6. pop_front()                     - удалить с начала
//   7. front()                         - первый элемент
//   8. insert_after(Node*, const T&)   - вставить после узла
//   9. erase_after(Node*)              - удалить после узла
//  10. clear()                         - очистить
//  11. reverse()                       - развернуть
//  12. size()                          - размер
//  13. empty()                         - пусто ли
//  14. begin()                         - начало списка

void test_push_front() {
  ForwardList<int> list;

  list.push_front(1);
  assert(list.size() == 1);
  assert(list.front() == 1);

  list.push_front(2);
  list.push_front(3);
  assert(list.size() == 3);
  assert(list.front() == 3);

  std::cout << "test_push_front passed" << std::endl;
}
// [_h]->[1]->[2]->[3]
void test_pop_front() {
  ForwardList<int> list;
  for (int i = 10; i > 0; i--) {
    list.push_front(i);
  }
  for (int i = 10; i > 0; i--) {
    assert(list.size() == i);
    list.pop_front();
  }
  assert(list.size() == 0);
  std::cout << "test_pop_front passed" << std::endl;
}
void test_copy_constructor() {
  ForwardList<int> list1;
  for (int i = 10; i > 0; i--) {
    list1.push_front(i);
  }
  ForwardList<int> list2(list1);
  assert(list1.size() == list2.size());
  for (int i = 1; i <= 10; i++) {
    assert(list2.front() == i);
    list2.pop_front();
  }
  std::cout << "test_copy_constructor passed" << std::endl;
}
void test_assignment_operator() {
  {
    ForwardList<int> list1, list2;
    for (int i = 10; i > 0; i--) {
      list1.push_front(i);
    }
    list2 = list1;
    assert(list1.size() == list2.size());
    for (int i = 1; i <= 10; i++) {
      assert(list2.front() == i);
      list2.pop_front();
    }
  }
  {
    ForwardList<int> list1, list2;
    for (int i = 10; i > 0; i--) {
      list1.push_front(i);
      list2.push_front(i);
      list2.push_front(i);
    }
    list2 = list1;
    assert(list1.size() == list2.size());
    for (int i = 1; i <= 10; i++) {
      assert(list2.front() == i);
      list2.pop_front();
    }
  }
  std::cout << "test_assignment_operator passed" << std::endl;
}
void test_front() {
  ForwardList<int> list;
  for (int i = 10; i > 0; i--) {
    list.push_front(i);
  }
  for (int i = 1; i <= 10; i++) {
    assert(list.front() == i);
    list.pop_front();
  }
  std::cout << "test_front passed" << std::endl;
}
void test_insert_after() {
  ForwardList<int> list;
  list.push_front(0);
  for (int i = 10; i > 0; i--) {
    list.insert_after(list.begin(), i);
  }
  assert(list.size() == 11);
  for (int i = 0; i <= 10; i++) {
    assert(list.front() == i);
    list.pop_front();
  }
  std::cout << "test_insert_after passed" << std::endl;
}
void test_erase_after() {
  ForwardList<int> list;
  for (int i = 10; i > 0; i--) {
    list.push_front(i);
  }
  for (int i = 0; i < 9; i++) {
    assert(list.front() == 1);
    assert(list.size() == 10 - i);
    list.erase_after(list.begin());
  }
  std::cout << "test_erase_after passed" << std::endl;
}
void test_clear() {
  ForwardList<int> list;
  list.clear();
  assert(list.size() == 0);
  for (int i = 0; i < 10; i++)
    list.push_front(i);
  list.clear();
  assert(list.size() == 0);
  std::cout << "test_clear passed" << std::endl;
}
void test_reverse() {
  ForwardList<int> list;
  for (int i = 0; i < 10; i++)
    list.push_front(i);
  list.reverse();
  assert(list.size() == 10);
  for (int i = 0; i < 10; i++) {
    assert(list.front() == i);
    list.pop_front();
  }
  std::cout << "test_reverse passed" << std::endl;
}
void test_size() {

}
void test_empty() {
  ForwardList<int> list;
  assert(list.empty() == true);
  for (int i = 0; i < 10; i++)
    list.push_front(i);
  assert(list.empty() == false);
}
void test_begin() {
  // And I threw it on the ground
  // Do you think I'm stupid?
  // My father is not a cellphone
}

int main() {
  std::cout << "Running ForwardList tests" << std::endl;
  test_push_front();
  test_pop_front();
  test_copy_constructor();
  test_assignment_operator();
  test_front();
  test_insert_after();
  test_erase_after();
  test_clear();
  test_reverse();
  test_empty();
  test_begin();
  std::cout << "All tests passed" << std::endl;
  return 0;
}
