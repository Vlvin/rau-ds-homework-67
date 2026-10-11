#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <typename T> class Vector {
private:
  T *_data;
  size_t _size;
  size_t _capacity;

  void _resize_capacity(size_t new_capacity) {
    if (new_capacity < _size || new_capacity == 0)
      throw std::invalid_argument("Too small to shrink");
    T *neodata = new T[new_capacity];
    for (int i = 0; i < _size; i++)
      neodata[i] = std::move(_data[i]);
    delete[] _data;
    _data = neodata;
    _capacity = new_capacity;
  }

public:
  /// 1. Конструктор по умолчанию
  Vector() : _data(new T[8]), _size(0), _capacity(8) {}

  /// 2. Конструктор с начальным размером
  Vector(size_t initial_size)
      : _data(new T[initial_size]), _size(0), _capacity(initial_size) {
    if (initial_size == 0) {
      throw std::invalid_argument("Can't have initial_size of 0");
    }
  }

  /// 3. Деструктор
  ~Vector() { delete[] _data; }

  /// 4. Конструктор копирования
  Vector(const Vector &other)
      : _data(new T[other._capacity]), _size(other._size),
        _capacity(other._capacity) {
    for (int i = 0; i < _size; i++)
      _data[i] = other._data[i];
  }

  /// 5. Оператор присваивания
  Vector &operator=(const Vector &other) {
    if (this == &other)
      return *this;
    delete[] _data;
    _data = new T[other._capacity];
    _size = other._size;
    _capacity = other._capacity;
    for (int i = 0; i < _size; i++)
      _data[i] = other._data[i];
    return *this;
  }

  /// 6. push_back(const T& value) - добавить в конец
  void push_back(const T &value) {
    if (_size == _capacity)
      _resize_capacity(_capacity * 2);
    _data[_size] = value;
    _size++;
  }

  /// 7. pop_back() - удалить последний элемент
  void pop_back() {
    if (_size == 0)
      return;
    _data[_size - 1] = T();
    _size--;
  }

  /// 8. operator[](size_t index) - доступ по индексу
  T &operator[](size_t index) { return _data[index]; }
  const T &operator[](size_t index) const { return _data[index]; }

  /// 9. at(size_t index) - доступ с проверкой границ
  T &at(size_t index) {
    if (index < 0 || _size <= index)
      throw std::out_of_range("index out of range");
    return _data[index];
  }
  const T &at(size_t index) const {
    if (index < 0 || _size <= index)
      throw std::out_of_range("index out of range");
    return _data[index];
  }

  /// 10. front() - первый элемент
  T &front() { return at(0); }
  const T &front() const { return at(0); }

  /// 11. back() - последний элемент
  T &back() { return at(_size - 1); }
  const T &back() const { return at(_size - 1); }

  void insert(int pos, const T &val) {
    if (pos < 0 || pos > _size)
      throw std::invalid_argument("pos out of range");
    if (_size == _capacity)
      _resize_capacity(_capacity * 2);
    _size++;
    for (int i = _size - 1; i > pos; i--)
      _data[i] = std::move(_data[i - 1]);
    _data[pos] = val;
  }

  void erase(int pos) {
    if (pos < 0 || pos >= _size)
      throw std::invalid_argument("pos out of range");
    for (int i = pos; i < _size - 1; i++)
      _data[i] = std::move(_data[i + 1]);
    _size--;
  }

  void swap(Vector &other) {
    std::swap(_data, other._data);
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
  }

  /// 12. size() - количество элементов
  size_t size() const { return _size; }

  /// 13. capacity() - выделенная память
  size_t capacity() const { return _capacity; }

  T *data() { return _data; }
  const T *data() const { return _data; }
  /// 14. empty() - пуст ли вектор
  bool empty() const { return 0 == _size; }

  /// 15. reserve(size_t new_capacity) - выделить память
  void reserve(size_t new_capacity) {
    _resize_capacity(new_capacity);
    // if (new_capacity < _size)
    //   throw std::invalid_argument("capacity must be >= size");
    // T *data = new T[new_capacity];
    // for (size_t i = 0; i < _size; i++)
    //   data[i] = std::move(_data[i]);
    // delete[] _data;
    // _data = data;
    // _capacity = new_capacity;
  }

  void resize(size_t new_size) {
    if (new_size > _capacity)
      reserve(new_size);
    for (int i = _size; i < new_size; i++)
      _data[i] = T();
    for (int i = new_size; i < _size; i++)
      _data[i] = T();
    _size = new_size;
  }

  /// 16. clear() - очистить вектор
  void clear() {
    for (int i = 0; i < _size; i++)
      _data[i] = T();
    _size = 0;
  }

  /// 17. begin() - начало вектора
  T *begin() { return &front(); }
  const T *begin() const { return &front(); }

  /// 18. end() - конец вектора
  T *end() { 
    if (_size == 0)
      return _data;
    return _data + _size;
  }
  const T *end() const { 
    if (_size == 0)
      return _data;
    return _data + _size;
  }
};
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

#endif // VECTOR_H
