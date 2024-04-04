#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief Given an array containing N integers, and a number S denoting a target
 * sum.
 *
 * Find two distinct integers that can pair up to form target sum. Let us assume
 * there will be only one such pair.
 *
 * @param arr N integers
 * @param sum target sum
 * @return vector<int> two distinct integers that can pair up to form target sum
 */
vector<int> pairSum(vector<int> arr, int sum) {
  vector<int> result;

  unordered_set<int> s;

  for (int i = 0; i < arr.size(); i++) {
    int x = sum - arr[i];
    if (s.find(x) != s.end()) {
      result.push_back(x);
      result.push_back(arr[i]);
      break;
    }
    s.insert(arr[i]);
  }

  return result;
}

TEST_CASE("Pairs", "[levelup]") {
  vector<int> arr{10, 5, 2, 3, -6, 9, 11};
  vector<int> expected{10, -6};
  int S = 4;

  auto result = pairSum(arr, S);

  REQUIRE(result == expected);
}
