#include <iostream>

#include "linkedlist.h"

int main() {
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  LinkedList *list = LinkedList::fromArray(numbers, 9);


  std::cout << list->asString() << std::endl;

  LinkedList::clear(list)
  return 0;
}
