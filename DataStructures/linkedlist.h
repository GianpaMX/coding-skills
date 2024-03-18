#pragma once

#include <string>

using namespace std;

class LinkedList {
 public:
  int data;
  LinkedList *next = NULL;

  LinkedList(const int data);
  LinkedList(const int data, LinkedList *next);

  static LinkedList *fromArray(const int *array, int size);
  static void clear(LinkedList *list);

  string asString();
};
