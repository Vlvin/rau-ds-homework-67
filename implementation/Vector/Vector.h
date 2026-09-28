#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;
    
    void _resize_capacity(size_t new_capacity);

public:
    /// 1. Конструктор по умолчанию
    Vector();
    
    /// 2. Конструктор с начальным размером
    Vector(size_t initial_size);
    
    /// 3. Деструктор
    ~Vector();
    
    /// 4. Конструктор копирования
    Vector(const Vector& other);
    
    /// 5. Оператор присваивания
    Vector& operator=(const Vector& other);
    
    /// 6. push_back(const T& value) - добавить в конец
    void push_back(const T& value);
    
    /// 7. pop_back() - удалить последний элемент
    void pop_back();
    
    /// 8. operator[](size_t index) - доступ по индексу
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    /// 9. at(size_t index) - доступ с проверкой границ
    T& at(size_t index);
    const T& at(size_t index) const;
    
    /// 10. front() - первый элемент
    T& front();
    const T& front() const;
    
    /// 11. back() - последний элемент
    T& back();
    const T& back() const;
    
    /// 12. size() - количество элементов
    size_t size() const;
    
    /// 13. capacity() - выделенная память
    size_t capacity() const;
    
    /// 14. empty() - пуст ли вектор
    bool empty() const;
    
    /// 15. reserve(size_t new_capacity) - выделить память
    void reserve(size_t new_capacity);
    
    /// 16. clear() - очистить вектор
    void clear();
    
    /// 17. begin() - начало вектора
    T* begin();
    const T* begin() const;
    
    /// 18. end() - конец вектора
    T* end();
    const T* end() const;
};

#endif // VECTOR_H
