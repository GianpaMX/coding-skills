#include <iostream>

#include "linkedlist.h"

int main() {
  int numbers[] = {1, 3, 5, 6, 7, 8, 9};
  LinkedList list = LinkedList::fromArray(numbers, 7);

  std::cout << list.asString() << std::endl;

  list.add(10);

  std::cout << list.asString() << std::endl;

  list.addFirst(0);

  std::cout << list.asString() << std::endl;

  list.add(2, 2);
  list.add(4, 4);

  std::cout << list.asString() << std::endl;

  std::cout << "Index of 10: " + to_string(list.indexOf(10)) << std::endl;
  std::cout << "Contains 11? " << (list.contains(11) ? "true" : "false")
            << std::endl;

  int *last = list.removeLast();
  std::cout << "Remove last (" << to_string(*last) << ")" << std::endl;
  delete last;
  std::cout << list.asString() << std::endl;

  int *i = list.remove(5);
  std::cout << "Remove index 5 (" << to_string(*i) << ")" << std::endl;
  delete i;
  std::cout << list.asString() << std::endl;

  int *first = list.removeFirst();
  std::cout << "Remove first (" << to_string(*first) << ")" << std::endl;
  delete first;
  std::cout << list.asString() << std::endl;

  std::cout << "Get index 3 (" << to_string(list.get(3)) << ")" << std::endl;

  std::cout << "Size (" << to_string(list.size()) << ")" << std::endl;

  int evenNumbers[] = {12, 14, 16, 18};
  LinkedList evenNumbersList = LinkedList::fromArray(evenNumbers, 4);
  std::cout << "Even numbers: " << evenNumbersList.asString() << std::endl;

  list.addAll(evenNumbersList);
  std::cout << list.asString() << std::endl;

  list.clear();
  return 0;
}
