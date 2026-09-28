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
    assert(v._size() == 1);
    assert(v[0] == 5);
    
    v.push_back(10);
    v.push_back(15);
    assert(v._size() == 3);
    assert(v.back() == 15);
    
    std::cout << "test_push_back passed" << std::endl;
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
    
    // Добавляйте свои тесты:
    // test_pop_back();
    // test_operator_bracket();
    
    std::cout << "All tests passed" << std::endl;
    return 0;
}
