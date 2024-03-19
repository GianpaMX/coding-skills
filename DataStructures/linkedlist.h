#pragma once

#include <string>

using namespace std;

class LinkedList {
 public:
  static LinkedList fromArray(const int *array, int size);
  void clear();

  bool isEmpty();

  void add(const int data);
  void add(const int index, const int data);
  void addFirst(const int data);

  int indexOf(const int data);
  bool contains(const int data);

  int *removeLast();
  int *remove(int index);

  string asString();

 private:
  class Node;
  Node *head = nullptr;

  int *removeNode(Node *node, Node *previousNode);
};
