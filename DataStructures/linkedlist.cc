#include "linkedlist.h"

LinkedList::LinkedList(int data) : LinkedList(data, NULL) {}

LinkedList::LinkedList(int data, LinkedList *next) : data(data), next(next) {}


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
