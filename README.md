# Data Structures Homework

Домашние задания по структурам данных на C++. Репо состоит из двух направлений: реализация собственных структур данных и решение задач на STL контейнеры.

## Структура

```
ds-homework/
├── implementation/          # Реализация структур данных с нуля
│   ├── Vector/
│   ├── CircularBuffer/
│   ├── Deque/
│   ├── ForwardList/
│   ├── DoublyLinkedList/
│   ├── Stack/
│   ├── Queue/
│   ├── Heap/
│   ├── BinarySearchTree/
│   ├── HashTable/
│   └── DisjointSets/
│
├── use/                     # Задачи на STL (submodule)
│   ├── problems/            # Описание задач
│   ├── vector/              # Решения для vector
│   ├── deque/               # Решения для deque
│   ├── stack_and_queue/     # Решения для stack/queue
│   └── ...
│
└── README.md
```

## Track 1: Implementation

Папка `implementation/` содержит структуры данных для самостоятельной реализации. В каждой папке структуры находятся файлы с интерфейсом и примерами тестов.

Детальные инструкции — в README папки `implementation/`.

## Track 2: Use

Папка `use/` содержит задачи на STL контейнеры. Описание всех задач находится в `problems/`, решения организованы по папкам (`vector/`, `deque/`, и т.д.).

Подробный процесс работы описан в `use/README.md`.

---

## Быстрый старт

```
git clone --recurse-submodules https://github.com/rau-ds-homework/ds-homework.git
```

Затем обратитесь к README в папке `implementation/` или `use/` в зависимости от выбранного трека.
