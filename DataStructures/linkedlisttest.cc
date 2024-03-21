#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "linkedlist.h"

SCENARIO("Take and Drop from a LinkedList", "[LinkedList]") {
  GIVEN("An empty LinkedList") {
    LinkedList list = LinkedList();
    WHEN("taking one element") {
      LinkedList result = list.take(1);
      THEN("result should be empty") { REQUIRE(result.isEmpty()); }
    }
    WHEN("dropping one element") {
      LinkedList result = list.drop(1);
      THEN("result should be empty") { REQUIRE(result.isEmpty()); }
    }
  }

  GIVEN("A list with one element") {
    int array[] = {0};
    LinkedList list = LinkedList::fromArray(array, 1);
    WHEN("taking one element") {
      LinkedList result = list.take(1);
      THEN("result size should be one") { REQUIRE(result.size() == 1); }
    }

    WHEN("dropping one element") {
      LinkedList result = list.drop(1);
      THEN("result size should be zero") { REQUIRE(result.size() == 0); }
    }

    WHEN("taking zero elements") {
      LinkedList result = list.take(0);
      THEN("result size should be zero") { REQUIRE(result.size() == 0); }
    }

    WHEN("dropping zero elements") {
      LinkedList result = list.drop(0);
      THEN("result size should be one") { REQUIRE(result.size() == 1); }
    }
  }

  GIVEN("A list with numbers from 0 to 9") {
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList list = LinkedList::fromArray(array, 10);
    WHEN("taking five elements") {
      LinkedList result = list.take(5);
      THEN("result size should be from 0 to 4") {
        REQUIRE(result.asString() == "[0 -> 1 -> 2 -> 3 -> 4]");
      }
    }

    WHEN("dropping five elements") {
      LinkedList result = list.drop(5);
      THEN("result should be from 5 to 9") {
        REQUIRE(result.asString() == "[5 -> 6 -> 7 -> 8 -> 9]");
      }
    }
  }
}
