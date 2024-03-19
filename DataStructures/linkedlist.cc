#include "linkedlist.h"

class LinkedList::Node {
 public:
  int data;
  Node *next = NULL;

  Node(const int data);
  Node(const int data, Node *next);

  static void clear(Node *head);
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

void LinkedList::clear() {
  Node::clear(this->head);
  this->head = nullptr;
}

bool LinkedList::isEmpty() { return head == nullptr; }

int LinkedList::size() {
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

  this->lastNode()->next = new Node(data);
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

void LinkedList::addAll(LinkedList list) {
  if (isEmpty()) {
    this->head = list.head;
    return;
  }
  lastNode()->next = list.head;
}

int LinkedList::indexOf(const int data) {
  int index = 0;
  Node *node = this->head;
  while (node != NULL) {
    if (node->data == data) return index;

    node = node->next;
    index++;
  }
  return -1;
}

bool LinkedList::contains(const int data) { return indexOf(data) != -1; }

int LinkedList::get(const int index) {
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

string LinkedList::asString() {
  string result = "";
  Node *iterator = this->head;

  while (iterator != nullptr) {
    result += to_string(iterator->data);

    if (iterator->next != nullptr) result += " → ";

    iterator = iterator->next;
  }

  return "[" + result + "]";
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

LinkedList::Node *LinkedList::lastNode() {
  if (isEmpty()) throw std::out_of_range("list is empty");
  Node *iterator = this->head;
  while (iterator->next != nullptr) iterator = iterator->next;
  return iterator;
}
