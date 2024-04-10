#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/**
 * @brief Given n non-negative integers representing an elevation map where the
 * width of each bar is 1, compute how much water it can trap after raining.
 *
 * @param arr
 * @return int
 */
int rains(vector<int> arr) {
  int n = arr.size();

  vector<int> hiRight(n, 0);
  for (int i = 0, hightest = 0; i < n; i++) {
    hightest = max(hightest, arr[i]);
    hiRight[i] = hightest;
  }

  vector<int> hiLeft(n, 0);
  for (int i = n - 1, hightest = 0; i >= 0; i--) {
    hightest = max(hightest, arr[i]);
    hiLeft[i] = hightest;
  }

  int rain = 0;
  for (int i = 0; i < n; i++) {
    rain += min(hiLeft[i], hiRight[i]) - arr[i];
  }

  return rain;
}

TEST_CASE("Rains", "[levelup]") {
  vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int expected = 6;

  auto result = rains(arr);

  REQUIRE(result == expected);
}
