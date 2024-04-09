#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/**
 * @brief Write a function that takes input an array of distinct integers, and
 * returns the length of highest mountain.
 *
 * A mountain is defined as adjacent integers that are strickly increasing until
 * they reach a peak, at wehich they become strictly decreasing.
 *
 * At leat 3 numbers are required to form a mountain.
 *
 * @param arr
 * @return int
 */
int mountain(const vector<int> &arr) {
  int result = 0;
  int n = arr.size();

  for (int i = 1; i < n - 2;) {
    if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {  // is a peak
      // count the peak
      int count = 1;
      // counting to the left
      for (int j = i; j >= 1 && arr[j] > arr[j - 1]; j--) {
        count++;
      }
      // counting to the right and moving forwards
      while (i <= n - 2 && arr[i] > arr[i + 1]) {
        count++;
        i++;
      }
      result = max(result, count);
    } else {
      // just move forwards
      i++;
    }
  }

  return result;
}

TEST_CASE("Mountain", "[levelup]") {
  vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
  int expected = 9;

  auto result = mountain(arr);

  REQUIRE(result == expected);
}
