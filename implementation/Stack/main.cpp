#include "Stack.h"
#include <cassert>
#include <exception>
#include <iostream>

// Реализуйте методы Stack<T>:
//   1. Stack()                         - конструктор
//   2. ~Stack()                        - деструктор
//   3. Stack(const &)                  - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push(const T&)                  - добавить
//   6. pop()                           - удалить
//   7. top()                           - вершина
//   8. size()                          - размер
//   9. capacity()                      - вместимость
//  10. is_empty()                      - пусто ли
//  11. clear()                         - очистить
//  12. peek()                          - просмотреть вершину
//  13. ...
//  14. ...

void test_push() {
  Stack<int> s;

  s.push(5);
  assert(s.size() == 1);
  assert(s.top() == 5);

  s.push(10);
  s.push(15);
  assert(s.size() == 3);
  assert(s.top() == 15);

  std::cout << "test_push passed" << std::endl;
}

void test_pop() {
  Stack<int> s;

  for (int i = 0; i < 10; i++)
    s.push(i);
  for (int i = 9; i >= 1; i--) {
    assert(s.top() == i);
    assert(s.size() == i + 1);
    s.pop();
    assert(s.top() == i - 1);
    assert(s.size() == i);
  }
  s.pop();
  assert(s.size() == 0);
  bool flag = false;
  try {
    s.pop();
  } catch(std::exception&) {
    flag = true;
  }
  assert(flag);
  std::cout << "test_pop passed" << std::endl;
}
void test_top() {
  Stack<int> s;
  // check for exception on top absense
  bool flag = false;
  try {
    s.top();
  } catch(std::exception&) {
    flag = true;
  }
  // check for accessing real top
  for (int i = 0; i < 10; i++) {
    s.push(i);
    assert(s.top() == i);
  }
  // check for mutability
  for (int i = 0; i < 10; i++) {
    s.top() = i * 2;
    assert(s.top() == i * 2);
  }
  std::cout << "test_top passed" << std::endl;
}

int main() {
  std::cout << "Running Stack tests" << std::endl;
  test_push();
  test_pop();
  test_top();
  std::cout << "All tests passed" << std::endl;
  return 0;
}
