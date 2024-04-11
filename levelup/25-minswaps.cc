#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/**
 * @brief Given an array of size N, find the minimun number of swaps needed to
 * make the array as sorted
 *
 * @param arr
 * @return int
 */
int minSwaps(vector<int> arr) {
  int n = arr.size();
  pair<int, int> arrWithIndexes[n];
  for (int i = 0; i < n; i++) {
    arrWithIndexes[i] = make_pair(arr[i], i);
  }
  sort(arrWithIndexes, arrWithIndexes + n);

  int result = 0;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    if (visited[i] || arrWithIndexes[i].second == i) continue;

    int j = i;
    int cycle = 0;
    while (!visited[j]) {
      visited[j] = true;
      cycle++;
      j = arrWithIndexes[j].second;
    }
    result += cycle - 1;
  }

  return result;
}

TEST_CASE("Min Swaps Example 1", "[levelup]") {
  vector<int> arr{5, 4, 3, 2, 1};
  int expected = 2;

  auto result = minSwaps(arr);

  REQUIRE(result == expected);
}

TEST_CASE("Min Swaps Example 2", "[levelup]") {
  vector<int> arr{10, 11, 5, 4, 3, 2, 1};
  int expected = 4;

  auto result = minSwaps(arr);

  REQUIRE(result == expected);
}

TEST_CASE("Min Swaps Example 3", "[levelup]") {
  vector<int> arr{2, 4, 5, 1, 3};
  int expected = 3;

  auto result = minSwaps(arr);

  REQUIRE(result == expected);
}
