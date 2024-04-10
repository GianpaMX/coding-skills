#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief Given an array containing N integers, find the length of the longest
 * band.
 *
 * A band is defined as subsequence which can be reordered in such a manner all
 * elements appear consecutive (ie with absolute difference of 1 between
 * neighbouring elements)
 *
 * A longest band is the band (subsequence) which contains maxium integers.
 *
 * @param arr array containing N integers
 * @return int the longest band
 */
int longestBand(vector<int> arr) {
  int maxCount = 0;

  unordered_set<int> s;

  int n = arr.size();
  for (int i = 0; i < n; i++) {
    s.insert(arr[i]);
  }

  for (int i = 0; i < n; i++) {
    if (s.find(arr[i] - 1) != s.end()) continue;

    int count = 1;
    while (s.find(arr[i] + count) != s.end()) {
      count++;
    }
    maxCount = max(maxCount, count);
  }

  return maxCount;
}

TEST_CASE("Longest Band", "[levelup]") {
  vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
  int expected = 8;

  auto result = longestBand(arr);

  REQUIRE(result == expected);
}
