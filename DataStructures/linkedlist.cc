#include "linkedlist.h"

class LinkedList::Node {
 public:
  int data;
  Node *next = NULL;

  Node(const int data);
  Node(const int data, Node *next);

  static void clear(Node *head);
  void addAll(const Node *other);
  Node *copy() const;
  Node *lastNode();
};

LinkedList::Node::Node(int data) : Node(data, nullptr) {}

LinkedList::Node::Node(int data, Node *next) : data(data), next(next) {}

void LinkedList::Node::clear(Node *head) {
  if (head == nullptr) return;
  clear(head->next);
  delete head;
}

LinkedList LinkedList::fromArray(const int *array, int size) {
  LinkedList list = LinkedList();

  for (int i = size - 1; i >= 0; i--) {
    Node *node = new Node(array[i], list.head);
    list.head = node;
  }

  return list;
}

LinkedList::LinkedList() {}

LinkedList::LinkedList(const LinkedList &other) { *this = other; }

LinkedList::~LinkedList() { clear(); }

void LinkedList::clear() {
  Node::clear(this->head);
  this->head = nullptr;
}

bool LinkedList::isEmpty() const { return head == nullptr; }

int LinkedList::size() const {
  int size = 0;
  Node *iterator = this->head;
  while (iterator != nullptr) {
    iterator = iterator->next;
    size++;
  }
  return size;
}

void LinkedList::add(const int data) {
  if (isEmpty()) {
    addFirst(data);
    return;
  }

  this->head->lastNode()->next = new Node(data);
}

void LinkedList::add(const int index, const int data) {
  if (index < 0) throw std::out_of_range("negative index");
  if (index == 0) return addFirst(data);

  Node *node = this->head;
  for (int i = 1; i < index; i++) {
    if (node == nullptr) throw std::out_of_range("index out of bound");
    node = node->next;
  }
  node->next = new Node(data, node->next);
}

void LinkedList::addFirst(const int data) {
  this->head = new Node(data, this->head);
}

void LinkedList::addAll(const LinkedList &list) {
  if (isEmpty()) {
    addAllFirst(list);
    return;
  }
  this->head->lastNode()->next = list.head->copy();
}

void LinkedList::addAllFirst(const LinkedList &list) {
  Node *result = list.head->copy();
  result->lastNode()->next = this->head;
  this->head = result;
}

int LinkedList::indexOf(const int data) const {
  int index = 0;
  Node *node = this->head;
  while (node != NULL) {
    if (node->data == data) return index;

    node = node->next;
    index++;
  }
  return -1;
}

bool LinkedList::contains(const int data) const { return indexOf(data) != -1; }

int LinkedList::get(const int index) const {
  if (isEmpty()) throw std::out_of_range("list is empty");
  if (index < 0) throw std::out_of_range("negative index");

  Node *iterator = this->head;
  int i = 0;

  while (i < index) {
    if (iterator->next == nullptr)
      throw std::out_of_range("index out of bound");

    iterator = iterator->next;
    i++;
  }

  return iterator->data;
}

int *LinkedList::removeLast() {
  if (isEmpty()) return nullptr;

  Node *lastNode = this->head;
  Node *secondLastNode = nullptr;

  while (lastNode->next != nullptr) {
    secondLastNode = lastNode;
    lastNode = lastNode->next;
  }

  return removeNode(lastNode, secondLastNode);
}

int *LinkedList::remove(int index) {
  if (isEmpty()) throw std::out_of_range("list is empty");
  if (index < 0) throw std::out_of_range("negative index");

  Node *iterator = this->head;
  Node *previousNode = nullptr;
  int i = 0;

  while (i < index) {
    if (iterator->next == nullptr)
      throw std::out_of_range("index out of bound");

    previousNode = iterator;
    iterator = iterator->next;
    i++;
  }

  return removeNode(iterator, previousNode);
}

int *LinkedList::removeFirst() { return remove(0); }

LinkedList LinkedList::take(int n) const {
  LinkedList result = LinkedList();
  if (n == 0 || isEmpty()) return result;

  Node *iterator = this->head;
  Node *resultIterator = new Node(this->head->data);
  result.head = resultIterator;

  for (int i = 1; i < n; i++) {
    iterator = iterator->next;
    resultIterator->next = new Node(iterator->data);
    resultIterator = resultIterator->next;
  }

  return result;
}

LinkedList LinkedList::drop(int n) const {
  LinkedList result = LinkedList();
  if (isEmpty()) return result;

  Node *iterator = this->head;
  for (int i = 0; i < n; i++) {
    iterator = iterator->next;
  }
  if (iterator == nullptr) return result;

  Node *resultIterator = new Node(iterator->data);
  result.head = resultIterator;

  while (iterator->next != nullptr) {
    iterator = iterator->next;
    resultIterator->next = new Node(iterator->data);
    resultIterator = resultIterator->next;
  }

  return result;
}

string LinkedList::asString(const string &separator) const {
  string result = "";
  Node *iterator = this->head;

  while (iterator != nullptr) {
    result += to_string(iterator->data);

    if (iterator->next != nullptr) result += separator;

    iterator = iterator->next;
  }

  return "[" + result + "]";
}

bool LinkedList::operator==(const LinkedList &rhs) const {
  const Node *lhsIterator = this->head;
  const Node *rhsIterator = rhs.head;

  while (lhsIterator != nullptr) {
    if (lhsIterator->data != rhsIterator->data) return false;

    lhsIterator = lhsIterator->next;
    rhsIterator = rhsIterator->next;
  }

  return lhsIterator == rhsIterator;
}

bool LinkedList::operator!=(const LinkedList &rhs) const {
  return !(*this == rhs);
}

LinkedList LinkedList::operator+(const LinkedList &rhs) const {
  LinkedList newList = LinkedList(*this);
  newList.addAll(rhs);
  return newList;
}

LinkedList &LinkedList::operator=(const LinkedList &rhs) {
  clear();
  if (rhs.isEmpty()) return *this;

  this->head = rhs.head->copy();

  return *this;
}

void LinkedList::Node::addAll(const LinkedList::Node *other) {
  if (other == nullptr) return;

  this->next = other->copy();
}

LinkedList::Node *LinkedList::Node::copy() const {
  const Node *iterator = this;
  Node *result = new Node(this->data);
  Node *resultIterator = result;

  while (iterator->next != nullptr) {
    resultIterator->next = new Node(iterator->next->data);

    iterator = iterator->next;
    resultIterator = resultIterator->next;
  }

  return result;
}

LinkedList::Node *LinkedList::Node::lastNode() {
  Node *iterator = this;
  while (iterator->next != nullptr) iterator = iterator->next;
  return iterator;
}

int *LinkedList::removeNode(Node *node, Node *previousNode) {
  if (previousNode == nullptr) {
    this->head = node->next;
  } else {
    previousNode->next = node->next;
  }

  int *data = new int();
  *data = node->data;

  delete node;

  return data;
}

std::ostream &operator<<(std::ostream &os, LinkedList const &value) {
  os << value.asString();
  return os;
}
