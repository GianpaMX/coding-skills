#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

int maxSubarraySum(vector<int> arr) {
  int n = arr.size();

  int maxSum = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    sum = sum + arr[i];
    maxSum = max(maxSum, sum);
    if (sum < 0) {
      maxSum = 0;
      sum = 0;
    }
  }

  return maxSum;
}

TEST_CASE("Max Subarray Sum Test 1", "[levelup]") {
  vector<int> arr{-1, 2, 3, 4, 5, -2};
  int expected = 14;

  auto result = maxSubarraySum(arr);

  REQUIRE(result == expected);
}

TEST_CASE("Max Subarray Sum Test 2", "[levelup]") {
  vector<int> arr{-1, 7, -3, 4, 5, -2};
  int expected = 13;

  auto result = maxSubarraySum(arr);

  REQUIRE(result == expected);
}

TEST_CASE("Max Subarray Sum Test 3", "[levelup]") {
  vector<int> arr{-1, -7, -3, -4, -5, -2};
  int expected = 0;

  auto result = maxSubarraySum(arr);

  REQUIRE(result == expected);
}

TEST_CASE("Max Subarray Sum Test 4", "[levelup]") {
  vector<int> arr{10, 2, -20, -1, 2, 3, 4, -2, 6, -8, 3};
  int expected = 13;

  auto result = maxSubarraySum(arr);

  REQUIRE(result == expected);
}
