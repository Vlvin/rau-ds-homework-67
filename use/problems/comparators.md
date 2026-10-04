# Задачи с пользовательскими компараторами

## Введение

В этих задачах вам нужно будет создвать собственные классы и использовать их в `std::sort`, в качестве элементов `std::set` или ключей `std::map`.
Для этого потребуется реализовать операторы сравнения (`operator<` или предоставить функтор сравнения).

**Важно помнить:**
- Для `std::set<T>` и `std::map<T, V>` тип `T` должен поддерживать оператор `<` или иметь пользовательский компаратор
- Оператор `<` должен определять строгий слабый порядок
- Два объекта считаются эквивалентными, если `!(a < b) && !(b < a)`

## Задачи

#### 1. Уникальные точки на плоскости

Создайте класс `Point`, представляющий точку на 2D плоскости с координатами `x` и `y` (целые числа).

Реализуйте:
- Конструктор `Point(int x, int y)`
- Оператор `operator<` для сравнения точек (сначала по `x`, затем по `y`)
- Метод `print()` для вывода точки в формате `(x, y)`

Напишите функцию `uniquePoints`, которая:
- Принимает `std::vector<Point>` с возможными дубликатами
- Использует `std::set<Point>` для удаления дубликатов
- Возвращает вектор уникальных точек в отсортированном порядке

**Пример использования:**
```cpp
std::vector<Point> points = {Point(1, 2), Point(3, 4), Point(1, 2), Point(2, 3)};
auto result = uniquePoints(points);
// result содержит 3 уникальные точки: (1, 2), (2, 3), (3, 4)
```

#### 2. Координаты в 3D пространстве

Создайте класс `Vector3D`:
- `double x, y, z` — координаты

Реализуйте:
- Конструктор `Vector3D(double x, double y, double z)`
- Метод `distanceTo(const Vector3D& other)` — возвращает евклидово расстояние до другого вектора
- Метод `print()` — для вывода координат

Напишите функцию `findClosestVectors`, которая:
- Принимает `std::vector<Vector3D>`, целевой вектор `target` и число `k`
- Создаёт функтор-компаратор, которая сравнивает векторы по расстоянию до `target`
- Использует `std::sort()` с этим компаратором для сортировки векторов
- Возвращает первые `k` векторов из отсортированного массива

**Требования к компаратору:**
- Если расстояния равны, сравнивать лексикографически (по x, затем y, затем z)

**Пример использования:**
```cpp
std::vector<Vector3D> vectors = {
    Vector3D(1, 0, 0),
    Vector3D(0, 1, 0),
    Vector3D(2, 2, 2),
    Vector3D(0, 0, 1)
};
auto closest = findClosestVectors(vectors, Vector3D(0, 0, 0), 2);
// Возвращает 2 ближайших вектора: (0,0,1) и (0,1,0)
// (все три имеют расстояние 1.0, порядок определяется лексикографически)
```

#### 3. Задачи с приоритетами

Создайте класс `Task`:
- `std::string description` — описание задачи
- `int priority` — приоритет (1-10, где 10 — наивысший)
- `int id` — уникальный идентификатор

Реализуйте:
- Конструктор и оператор `operator<` (по убыванию приоритета, затем по возрастанию id)

Создайте класс `TaskManager` с методами:
- `addTask(Task task)` — добавляет задачу в `std::set<Task>`
- `getNextTask()` — возвращает и удаляет задачу с наивысшим приоритетом
- `removeTask(int id)` — удаляет задачу по id
- `getAllTasks()` — возвращает все задачи в порядке приоритета

**Пример использования:**
```cpp
TaskManager tm;
tm.addTask(Task("Fix bug", 8, 1));
tm.addTask(Task("Write docs", 5, 2));
tm.addTask(Task("Review code", 8, 3));
Task next = tm.getNextTask();
// next — "Fix bug" (приоритет 8, меньший id)
```

#### 4. Интервалы времени

Создайте класс `TimeInterval`:
- `int start` — время начала (в минутах от полуночи)
- `int end` — время окончания

Реализуйте:
- Конструктор
- Оператор `operator<`:
  - Ваша реализация должна быть такой, чтобы при добавлении интервалов в `std::set` пересекающиеся интервалы считались равными с точки зрения порядка.
  - Это приведёт к тому, что `std::set` не позволит добавить пересекающийся интервал, автоматически удаляя пересечения.

Напишите функцию `getNonOverlapingIntervals`, которая:
- Принимает `std::vector<TimeInterval>`
- Возвращает вектор непересекающихся интервалов
- Использует `std::set<TimeInterval>`

**Пример использования:**
```cpp
std::vector<TimeInterval> intervals = {
    TimeInterval(60, 120),
    TimeInterval(100, 180),
    TimeInterval(200, 240)
};

auto merged = getNonOverlapingIntervals(intervals);
// Ожидаемый результат: [(60,120), (200,240)]
```

#### 5. Транзакции по категориям

Создайте класс `Transaction`:
- `std::string category` — категория транзакции
- `double amount` — сумма транзакции
- `int timestamp` — время транзакции (Unix timestamp)

Реализуйте:
- Конструктор
- Оператор `operator<` для сравнения (сначала по категории, затем по timestamp)

Создайте класс `TransactionManager` для управления транзакциями:
- Внутри класса используйте `std::map<std::string, std::set<Transaction>>` для хранения транзакций, сгруппированных по категориям.
- Метод `addTransaction(const Transaction& t)` — добавляет транзакцию
- Метод `getTotalByCategory(const std::string& category)` — возвращает общую сумму по категории
- Метод `getTotalByCategoryInTimeRange(const std::string& category, int start, int end)` — возвращает общую сумму по категории в указанном временном интервале
- Метод `getAllCategories()` — возвращает `std::vector<std::string>` со всеми категориями

**Пример использования:**
```cpp
TransactionManager manager;
manager.addTransaction(Transaction("Food", 50.0, 1000));
manager.addTransaction(Transaction("Transport", 20.0, 1001));
manager.addTransaction(Transaction("Food", 30.0, 1002));
manager.addTransaction(Transaction("Food", 25.0, 1500));

double foodTotal = manager.getTotalByCategory("Food");
// foodTotal == 105.0

double foodInRange = manager.getTotalByCategoryInTimeRange("Food", 1000, 1002);
// foodInRange == 80.0

auto categories = manager.getAllCategories();
// categories содержит ["Food", "Transport"]
```

**Требования:**
- Все методы должны работать эффективно, используя преимущества структур данных `std::map` и `std::set`
- Временной интервал задается включительно: `[start, end]`
- Если категория не найдена, соответствующие методы должны возвращать 0.0
