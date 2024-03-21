#pragma once

#include <string>

using namespace std;

class LinkedList {
 public:
  static LinkedList fromArray(const int *array, int size);

  LinkedList();
  LinkedList(const LinkedList &other);
  ~LinkedList();
  void clear();

  bool isEmpty() const;
  int size() const;

  void add(const int data);
  void add(const int index, const int data);
  void addFirst(const int data);

  void addAll(const LinkedList &list);
  void addAllFirst(const LinkedList &list);

  int indexOf(const int data) const;
  bool contains(const int data) const;
  int get(const int index) const;

  int *removeLast();
  int *remove(int index);
  int *removeFirst();

  LinkedList take(int n) const;
  LinkedList drop(int n) const;

  string asString(const string &separator = string(" -> ")) const;

  bool operator==(const LinkedList &rhs) const;
  bool operator!=(const LinkedList &rhs) const;

  LinkedList operator+(const LinkedList &rhs) const;
  LinkedList &operator=(const LinkedList &rhs);

 private:
  class Node;
  Node *head = nullptr;

  int *removeNode(Node *node, Node *previousNode);
};

std::ostream &operator<<(std::ostream &os, LinkedList const &value);
