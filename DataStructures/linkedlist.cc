#include "linkedlist.h"

LinkedList::LinkedList(int data) : LinkedList(data, NULL) {}

LinkedList::LinkedList(int data, LinkedList *next) : data(data), next(next) {}

LinkedList *LinkedList::fromArray(const int *array, int size) {
  LinkedList *result = NULL;

  for (int i = size - 1; i >= 0; i--) {
    LinkedList *node = new LinkedList(array[i], result);
    result = node;
  }

  return result;
}

void LinkedList::clear(LinkedList *list) {
  if (list->next != NULL) clear(list->next);

  delete list;
}

LinkedList *LinkedList::add(const int data) {
  LinkedList *lastNode = this;

  while (lastNode->next != NULL) lastNode = lastNode->next;

  lastNode->next = new LinkedList(data);

  return this;
}

LinkedList *LinkedList::add(const int index, const int data) {
  if (index == 0) return addFirst(data);

  LinkedList *node = this;
  for (int i = 1; i < index; i++) {
    node = node->next;
  }
  node->next = new LinkedList(data, node->next);

  return this;
}

LinkedList *LinkedList::addFirst(const int data) {
  return new LinkedList(data, this);
}

string LinkedList::asString() {
  string result = "";
  LinkedList *iterator = this;

  while (iterator != NULL) {
    result += to_string(iterator->data);

    if (iterator->next != NULL) result += " → ";

    iterator = iterator->next;
  }

  return "[" + result + "]";
}
