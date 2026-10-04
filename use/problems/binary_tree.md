# Двоичное дерево

## Что такое укорененное дерево?
**Укорененное дерево** — это связный ациклический граф, в котором один из узлов выбран в качестве корня.
Если между двумя узлами есть ребро и один узел находится ближе к корню, то он называется родителем, а другой — потомком (или дочерним узлом). Каждый узел, кроме корня, имеет ровно одного родителя.

* **Лист** — это узел, у которого нет потомков.
* **Высота дерева** — это максимальное расстояние от корня до любого листа.
* **Уровень узла** — это расстояние от корня до этого узла.

## Что такое двоичное дерево?
**Двоичное дерево** — это частный случай укорененного дерева, где каждый узел может иметь не более двух потомков.
Эти потомки называются левым и правым дочерними узлами.
Узел содержит данные и указатели на левого и правого потомка (которые могут быть пустыми).

## Пример простой реализации двоичного дерева
```cpp
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
}
```

## Практические задания

#### 1. Подсчёт количества узлов
Напишите функцию `countNodes`, которая:
- Принимает указатель на корень двоичного дерева.
- Возвращает общее количество узлов в дереве.
- Если узел пустой (`nullptr`), возвращает 0.
- Рекурсивно обходит дерево.

**Пример использования:**
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);

int count = countNodes(root);
// count = 4
```

#### 2. Вычисление высоты дерева
Создайте функцию `treeHeight`, которая:
- Принимает указатель на корень двоичного дерева.
- Возвращает высоту дерева (длину самого длинного пути от корня до листа).
- Высота пустого дерева (`nullptr`) равна 0.
- Рекурсивно обходит дерево.

**Пример использования:**
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);

int height = treeHeight(root);
// height = 3
```

#### 3. Подсчёт листовых узлов
Напишите функцию `countLeaves`, которая:
- Принимает указатель на корень двоичного дерева.
- Возвращает количество листьев.
- Узел является листом, если оба его потомка (`left` и `right`) равны `nullptr`.
- Рекурсивно обходит дерево.

**Пример использования:**
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);

int leaves = countLeaves(root);
// leaves = 3 (узлы 3, 4, 5)
```

#### 4. Обходы дерева
Реализуйте три функции для различных способов обхода дерева:
- `preorder(TreeNode* root)` — прямой обход (Корень–Левый–Правый).
- `inorder(TreeNode* root)` — симметричный обход (Левый–Корень–Правый).
- `postorder(TreeNode* root)` — обратный обход (Левый–Правый–Корень).

Каждая функция выводит значения узлов в соответствующем порядке.

**Пример использования:**
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);

preorder(root);   // Вывод: 1 2 3
inorder(root);    // Вывод: 2 1 3
postorder(root);  // Вывод: 2 3 1
```

#### 5. Обход в ширину (по уровням)
Напишите функцию `levelOrder`, которая:
- Принимает указатель на корень двоичного дерева.
- Выводит узлы дерева по уровням (слева направо).
- Использует очередь (`std::queue<TreeNode*>`) для итеративного обхода.
- Сначала обрабатывает корень, затем все узлы первого уровня, затем второго и так далее.

**Пример использования:**
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);

levelOrder(root);
// Вывод: 1 2 3 4 5
```

#### 6. Сумма всех значений узлов
Создайте функцию `sumNodes`, которая:
- Принимает указатель на корень двоичного дерева.
- Возвращает сумму всех значений узлов.
- Если узел пустой, возвращает 0.

**Пример использования:**
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);

int sum = sumNodes(root);
// sum = 10
```

#### 7. Поиск максимального и минимального значения
Напишите две функции:
- `findMax(TreeNode* root)` — возвращает максимальное значение в дереве.
- `findMin(TreeNode* root)` — возвращает минимальное значение в дереве.

**Пример использования:**
```cpp
TreeNode* root = new TreeNode(5);
root->left = new TreeNode(3);
root->right = new TreeNode(8);
root->left->left = new TreeNode(1);

int maxVal = findMax(root);  // maxVal = 8
int minVal = findMin(root);  // minVal = 1
```

#### 8. Проверка идентичности деревьев
Создайте функцию `areIdentical`, которая:
- Принимает указатели на корни двух деревьев.
- Возвращает `true`, если оба дерева имеют одинаковую структуру и значения узлов.

**Пример использования:**
```cpp
TreeNode* tree1 = new TreeNode(1);
tree1->left = new TreeNode(2);
tree1->right = new TreeNode(3);

TreeNode* tree2 = new TreeNode(1);
tree2->left = new TreeNode(2);
tree2->right = new TreeNode(3);

bool identical = areIdentical(tree1, tree2);
// identical = true
```

#### 9. Подсчёт узлов на заданной глубине
Напишите функцию `countNodesAtDepth`, которая:
- Принимает указатель на корень дерева и уровень `k` (корень находится на уровне 1).
- Возвращает количество узлов на уровне `k`.

**Пример использования:**
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);

int count = countNodesAtDepth(root, 3);
// count = 2 (узлы 4 и 5)
```

#### 10. Отражение дерева
Создайте функцию `mirrorTree`, которая:
- Принимает указатель на корень дерева.
- Меняет местами левого и правого потомка для каждого узла рекурсивно.
- Преобразует дерево в его зеркальное отображение.
- Изменяет исходное дерево (работает на месте).

**Пример использования:**
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);

mirrorTree(root);
// Теперь: root->right = 2, root->left = 3, root->right->right = 4
```
