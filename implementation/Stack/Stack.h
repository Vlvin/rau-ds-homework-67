#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <stdexcept>
template <typename T> class Stack {
private:
  T *_data;
  int _capacity;
  int _size;

  void expand() {
    if (_capacity == 0)
      _capacity = DEF_SIZE;
    else
      _capacity *= 2;
    T *data = new T[_capacity];
    for (int i = 0; i < _size; i++)
      _data[i] = std::move(_data[i]);
  }

  static constexpr size_t DEF_SIZE = 8;

public:
  /// 1. Конструктор по умолчанию
  Stack() : _data(new T[DEF_SIZE]), _capacity(DEF_SIZE), _size(0) {}

  /// 2. Деструктор
  ~Stack() { delete[] _data; }

  /// 3. Конструктор копирования
  Stack(const Stack &other)
      : _data(new T[other._size]), _capacity(other._capacity),
        _size(other._size) {
    for (int i = 0; i < other._size; i++)
      _data[i] = other._data[i];
  }

  /// 4. Оператор присваивания
  Stack &operator=(const Stack &other) {
    if (this == &other)
      return *this;
    delete[] _data;
    _data = new T[other._size];
    _capacity = other._capacity;
    _size = other._size;
    for (int i = 0; i < other._size; i++)
      _data[i] = other._data[i];
    return *this;
  }

  /// 5. push(const T& x) - добавить в стек
  void push(const T &x) {
    if (_size == _capacity)
      expand();
    _data[_size] = x;
    _size++;
  }

  /// 6. pop() - удалить с вершины
  void pop() {
    if (_size == 0)
      throw std::runtime_error("Stack is empty");
    _size--;
    _data[_size] = T();
  }

  /// 7. top() - вершина стека
  T &top() {
    if (_size == 0)
      throw std::runtime_error("Stack is empty");
    return _data[_size - 1];
  }
  const T &top() const {
    if (_size == 0)
      throw std::runtime_error("Stack is empty");
    return _data[_size - 1];
  }

  /// 8. size() - количество элементов
  int size() const { return _size; }

  /// 9. capacity() - вместимость
  int capacity() const { return _capacity; }

  /// 10. is_empty() - пуст ли
  bool is_empty() const { return _size == 0; }

  /// 11. clear() - очистить
  void clear() {
    for (int i = 0; i < _size; i++)
      _data[i] = T();
    _size = 0;
  }

  /// 12. peek() - посмотреть вершину без удаления
  T &peek() { return top(); }
  const T &peek() const { return top(); }
};

#endif // STACK_H
