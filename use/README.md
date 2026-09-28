# STL задачи

Папка содержит решения задач с использованием стандартных контейнеров.

## Структура

```
use/
├── problems/               # Описание задач
│   ├── vector.md
│   ├── deque.md
│   ├── stack_and_queue.md
│   ├── set.md
│   ├── map.md
│   └── ...
│
├── vector/                 # Решения для vector.md
├── deque/                  # Решения для deque.md
├── stack_and_queue/        # Решения для stack_and_queue.md
└── README.md
```

## Процесс работы

### 1. Прочитайте задачу

Файлы задач находятся в папке `problems/`: `vector.md`, `deque.md`, `stack_and_queue.md` и т.д.

### 2. Создайте папку для решений

Если вы работаете с вектором, потребуется папка `vector/`. Аналогично для других контейнеров.

### 3. Создайте файл решения

Файл называется по имени функции или класса из задачи. Например, если задача требует функцию `reverse_vector`, то файл будет `vector/reverse_vector.cpp`.

### 4. Реализуйте функцию и напишите тесты

Каждый файл `.cpp` содержит:
- Реализацию функции или класса
- Набор тестов (основные случаи и граничные)
- Функцию `main()` для запуска тестов

Пример содержимого `vector/reverse_vector.cpp`:

```cpp
#include <vector>
#include <iostream>
#include <cassert>

std::vector<int> reverse_vector(const std::vector<int>& v) {
    std::vector<int> result = v;
    std::reverse(result.begin(), result.end());
    return result;
}

void test_reverse_vector() {
    // Простой случай
    std::vector<int> v = {1, 2, 3};
    std::vector<int> expected = {3, 2, 1};
    assert(reverse_vector(v) == expected);
    
    // Пустой вектор
    assert(reverse_vector({}).empty());
    
    // Один элемент
    assert(reverse_vector({5}) == std::vector<int>{5});
    
    // Два элемента
    assert(reverse_vector({1, 2}) == std::vector<int>{2, 1});
    
    std::cout << "reverse_vector passed" << std::endl;
}

int main() {
    test_reverse_vector();
    return 0;
}
```

## Требования к тестам

Тесты включают:
- Стандартные случаи с обычными входными данными
- Граничные случаи (пустой контейнер, один элемент, повторяющиеся значения)
- Проверки условий через `assert()`
