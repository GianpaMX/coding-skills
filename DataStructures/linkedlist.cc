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
