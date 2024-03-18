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

  LinkedList *add(const int data);
  LinkedList *addFirst(const int data);

  string asString();
};
