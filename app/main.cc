#include <iostream>

#include "linkedlist.h"

int main() {
  LinkedList list = LinkedList(0);

  std::cout << list.asString() << std::endl;

  return 0;
}
