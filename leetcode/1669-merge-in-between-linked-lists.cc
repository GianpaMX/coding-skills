#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "linkedlist.h"

/**
 * @brief
 * You are given two linked lists: list1 and list2 of sizes n and m
 * respectively.
 *
 * Remove list1's nodes from the ath node to the bth node, and put list2 in
 * their place.
 *
 * Build the result list and return its head.
 *
 * @param list1 3 <= list1.length <= 104
 * @param a 1 <= a <= b < list1.length - 1
 * @param b 1 <= a <= b < list1.length - 1
 * @param list2 1 <= list2.length <= 104
 * @return LinkedList
 */
LinkedList mergeInBetween(const LinkedList &list1, int a, int b,
                          const LinkedList &list2) {
  LinkedList left = list1.take(a);
  LinkedList right = list1.drop(b + 1);
  LinkedList first = left + list2;
  LinkedList second = first + right;
  return second;
}

/**
 * @brief Example 1:
 *
 * Input:
 *  list1 = [10,1,13,6,9,5]
 *  a = 3
 *  b = 4
 *  list2 = [1000000,1000001,1000002]
 *
 * Output: [10,1,13,1000000,1000001,1000002,5]
 *
 * Explanation: We remove the nodes 3 and 4 and put the entire list2 in their
 * place. The blue edges and nodes in the above figure indicate the result.
 *
 */
TEST_CASE("Merge In Between Linked Lists Example 1", "[1669]") {
  int array1[] = {10, 1, 13, 6, 9, 5};
  int a = 3;
  int b = 4;
  int array2[] = {1000000, 1000001, 1000002};
  int arrayExpected[] = {10, 1, 13, 1000000, 1000001, 1000002, 5};
  LinkedList expected = LinkedList::fromArray(arrayExpected, 7);
  LinkedList list1 = LinkedList::fromArray(array1, 6);
  LinkedList list2 = LinkedList::fromArray(array2, 3);

  LinkedList result = mergeInBetween(list1, a, b, list2);

  REQUIRE(result == expected);
}

/**
 * @brief Example 2:
 *
 * Input:
 *  list1 = [0,1,2,3,4,5,6]
 *  a = 2
 *  b = 5
 *  list2 = [1000000,1000001,1000002,1000003,1000004]
 *
 * Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
 *
 * Explanation: The blue edges and nodes in the above figure indicate the
 * result.
 *
 */
TEST_CASE("Merge In Between Linked Lists Example 2", "[1669]") {
  int array1[] = {0, 1, 2, 3, 4, 5, 6};
  int a = 2;
  int b = 5;
  int array2[] = {1000000, 1000001, 1000002, 1000003, 1000004};
  int arrayExpected[] = {0, 1, 1000000, 1000001, 1000002, 1000003, 1000004, 6};
  LinkedList expected = LinkedList::fromArray(arrayExpected, 8);
  LinkedList list1 = LinkedList::fromArray(array1, 7);
  LinkedList list2 = LinkedList::fromArray(array2, 5);

  LinkedList result = mergeInBetween(list1, a, b, list2);

  REQUIRE(result == expected);
}
