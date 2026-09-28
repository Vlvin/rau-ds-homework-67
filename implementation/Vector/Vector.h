#pragma once

#include <cstddef>
#include <stdexcept>
template <typename T> class Vector {
public:
  // Реализуйте методы Vector<T>:
#define DEF_CAP 8
  Vector() : _size(0), _capacity(DEF_CAP), _data(new T[DEF_CAP]) {}
  ~Vector() {
    delete[] _data;
  }
  Vector(const Vector &other) {

  }
  void operator=(const Vector &other);
  void push_back(const T &x) {
    if (_size == _capacity)
      realloc(2 * _capacity);
    _data[_size++] = x;
  }
  void pop_back() {
    if (_size == 0) {
      static_assert(false, "Do smth");
    }
    _size--;
  }
  void operator[](int index);
  void back();
  void insert(int pos, const T &val);
  void erase(int pos);
  void swap(Vector &other);
  void clear();
  void resize(int new_size);
  void front();

private:
  void realloc(size_t new_cap) {
    if (new_cap <= _size)
      throw std::invalid_argument("Can't realloc");
    T *data = new T[new_cap];
    for (size_t i = 0; i < _size; i++)
      data[i] = std::move(_data[i]);
    delete[] _data;
    _data = data;
  }

private:
  T *_data;
  size_t _capacity, _size;
};
