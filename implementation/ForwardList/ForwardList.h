#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <stdexcept>
template <typename T> class ForwardList {
private:
  struct Node {
    T data;
    Node *next;
    Node(const T &d = T(), Node *n = nullptr) : data(d), next(n) {}
  };

  Node *_head;
  int _size;

public:
  /// 1. Конструктор по умолчанию
  ForwardList() : _head(new Node()), _size(0) {}

  /// 2. Деструктор
  ~ForwardList() {
    clear();
    delete _head;
  }

  /// 3. Конструктор копирования
  ForwardList(const ForwardList &other) : _head(new Node()), _size(other._size) {
    Node *thead = _head;
    Node *ohead = other._head;
    while (ohead->next != nullptr) {
      thead->next = new Node(ohead->next->data);
      thead = thead->next;
      ohead = ohead->next;
    }
  }

  /// 4. Оператор присваивания
  ForwardList &operator=(const ForwardList &other) {
    if (this == &other)
      return *this;
    clear();
    _size = other._size;
    Node *thead = _head;
    Node *ohead = other._head;
    while (ohead->next != nullptr) {
      thead->next = new Node(ohead->next->data);
      thead = thead->next;
      ohead = ohead->next;
    }
    return *this;
  }

  /// 5. push_front(const T& x) - добавить в начало
  void push_front(const T &x) { insert_after(_head, x); }

  /// 6. pop_front() - удалить с начала
  void pop_front() { erase_after(_head); }

  /// 7. front() - первый элемент
  T &front() {
    if (_head->next == nullptr)
      throw std::logic_error("List is empty");
    return _head->next->data;
  }
  const T &front() const {
    if (_head->next == nullptr)
      throw std::logic_error("List is empty");
    return _head->next->data;
  }

  /// 8. insert_after(Node* node, const T& value) - вставить после узла
  void insert_after(Node *node, const T &value) {
    if (node == nullptr) throw std::invalid_argument("node can't be null");
    node->next = new Node(value, node->next);
    _size++;
  }

  /// 9. erase_after(Node* node) - удалить после узла
  void erase_after(Node *node) {
    if (node == nullptr || node->next == nullptr)
      throw std::invalid_argument("nothing to erase");
    Node *tmp = node->next;
    node->next = tmp->next;
    delete tmp;
    _size--;
  }

  /// 10. clear() - очистить
  void clear() {
    while (_head != nullptr && _head->next != nullptr) {
      pop_front();
    }
  }

  /// 11. reverse() - развернуть
  void reverse() {
    ForwardList fl;
    while (size() != 0) {
      fl.push_front(std::move(front()));
      pop_front();
    }
    swap(fl);
  }

  void swap(ForwardList &other) {
    std::swap(other._size, _size);
    std::swap(other._head, _head);
  }

  /// 12. size() - количество элементов
  int size() const { return _size; }

  /// 13. empty() - пуст ли
  bool empty() const { return _size == 0; }

  /// 14. begin() - начало списка
  Node *begin() { return _head->next; }
  const Node *begin() const { return _head->next; }
};

#endif // FORWARDLIST_H
