#include "Vector.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Vector<T>:
//
//   1. Vector()                        - конструктор по умолчанию
//   2. ~Vector()                       - деструктор
//   3. Vector(const Vector& other)     - конструктор копирования
//   4. operator=(const Vector& other)  - оператор присваивания
//   5. push_back(const T& x)           - добавить в конец
//   6. pop_back()                      - удалить с конца
//   7. operator[](int index)           - доступ по индексу
//   8. back()                          - последний элемент
//   9. insert(int pos, const T& val)   - вставить
//  10. erase(int pos)                  - удалить
//  11. swap(Vector& other)             - обменять содержимое
//  12. clear()                         - очистить
//  13. resize(int new_size)            - изменить размер
//  14. front()                         - первый элемент
//
// Напишите для каждой функции один тест:
//   void test_<название_функции>() { ... }
//
// Каждый тест должен проверять:
//   - Нормальный случай
//   - Граничные случаи

void test_push_back() {
  Vector<int> v;

  // Нормальный случай
  v.push_back(5);
  assert(v.size() == 1);
  assert(v[0] == 5);

  v.push_back(10);
  v.push_back(15);
  assert(v.size() == 3);
  assert(v.back() == 15);

  v = Vector<int>(1); // small vector to make it reallocate soon
  for (int i = 0; i < 100; i++)
    v.push_back(i * 10);
  for (int i = 0; i < 100; i++)
    assert(v[i] == i * 10);

  std::cout << "test_push_back passed" << std::endl;
}

void test_pop_back() {
  Vector<int> v;
  v.push_back(5); // already tested, it works fine
  v.pop_back();
  assert(v.size() == 0);
  v.pop_back(); // if empty, just ignores it
  assert(v.size() == 0);
  std::cout << "test_pop_back passed" << std::endl;
}
void test_operator_bracket() {
  Vector<int> v;
  for (int i = 0; i < 100; i++)
    v.push_back(i * 10);
  for (int i = 0; i < 100; i++)
    assert((i * 10) == v[i]);
  std::cout << "test_operator_bracket passed" << std::endl;
}

void test_back() {
  // OH NOO MY BACK, IT HURTS, I'M TOO OLD TO TEST IT
  Vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
    assert(i == v.back());
  }
  v.back() = 25;
  assert(25 == v.at(v.size() - 1));
  v.back() = 9;
  for (int i = 9; i >= 0; i--) {
    assert(i == v.back());
    v.pop_back();
  }
  std::cout << "test_back passed" << std::endl;
}
void test_front() {
  Vector<int> v;
  v.push_back(12);
  assert(12 == v.front());
  v.front() = 25;
  assert(25 == v.at(0));
  std::cout << "test_front passed" << std::endl;
}

void test_insert() {
  Vector<int> v;
  v.insert(0, 125);
  assert(125 == v.at(0));
  v.insert(0, 521);
  assert(521 == v.at(0));
  v.insert(v.size(), 666);
  assert(666 == v.at(v.size() - 1));
  std::cout << "test_insert passed" << std::endl;
}
void test_erase() {
  Vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  for (int i = 0; i < 10; i++) {
    assert(i == v.at(0));
    v.erase(0);
  }
  std::cout << "test_erase passed" << std::endl;
}

void test_swap() {
  Vector<int> a, b;
  for (int i = 0; i < 10; i++)
    a.push_back(i);
  auto as = a.size();
  auto ac = a.capacity();
  auto ad = a.data();
  auto bs = b.size();
  auto bc = b.capacity();
  auto bd = b.data();
  a.swap(b);
  assert(b.size() == as);
  assert(b.capacity() == ac);
  assert(b.data() == ad);

  assert(a.size() == bs);
  assert(a.capacity() == bc);
  assert(a.data() == bd);
  std::cout << "test_swap passed" << std::endl;
}
void test_clear() {
  Vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);
  auto vc = v.capacity();
  auto vd = v.data();
  v.clear();
  assert(v.size() == 0);
  assert(v.capacity() == vc);
  assert(v.data() == vd);
  std::cout << "test_clear passed" << std::endl;
}
void test_resize() {
  {
    Vector<int> v;
    v.resize(10);
    assert(v.size() == 10);
    assert(v.capacity() == 10);
    for (int i = 0; i < 10; i++)
      assert(int() == v.at(i));
  }
  {
    Vector<int> v;
    for (int i = 0; i < 10; i++)
      v.push_back(i);
    v.resize(20);
    assert(v.size() == 20);
    assert(v.capacity() == 20);
    for (int i = 0; i < 10; i++)
      assert(i == v.at(i));
    for (int i = 10; i < 20; i++)
      assert(int() == v.at(i));
  }
  std::cout << "test_resize passed" << std::endl;
}
void test_copy_constructor() {
  Vector<int> a;
  for (int i = 0; i < 10; i++)
    a.push_back(i);
  Vector<int> b(a);
  assert(a.size() == b.size());
  assert(a.capacity() == b.capacity());
  for (int i = 0; i < a.size(); i++)
    assert(a.at(i) == b.at(i));
  std::cout << "test_copy_constructor passed" << std::endl;
}
void test_assignment_operator() {
  Vector<int> a, b;
  for (int i = 0; i < 10; i++)
    a.push_back(i);
  b = a;
  assert(a.size() == b.size());
  assert(a.capacity() == b.capacity());
  for (int i = 0; i < a.size(); i++)
    assert(a.at(i) == b.at(i));
  std::cout << "test_assignment_operator passed" << std::endl;
}
// void test_pop_back() { ... }
// void test_operator_bracket() { ... }
// void test_back() { ... }
// void test_front() { ... }
// void test_insert() { ... }
// void test_erase() { ... }
// void test_swap() { ... }
// void test_clear() { ... }
// void test_resize() { ... }
// void test_copy_constructor() { ... }
// void test_assignment_operator() { ... }

int main() {
  std::cout << "Running Vector tests" << std::endl;
  test_push_back();
  test_pop_back();
  test_operator_bracket();
  test_back();
  test_front();
  test_insert();
  test_erase();
  test_swap();
  test_clear();
  test_resize();
  test_copy_constructor();
  test_assignment_operator();
  std::cout << "All tests passed" << std::endl;
  return 0;
}
