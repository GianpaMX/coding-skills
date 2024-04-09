#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

/**
 * @brief Given an array containing N integers, and an number S denoting a
 * target sum.
 *
 * Find all distinct integers that can add up to form target sum. The numbers in
 * each triplet should be ordered in ascending ordr, and triplets should be
 * ordered too.
 *
 * Return empty array if no such triplet exists.
 *
 * This problem is very similar to 13-pairs with the difference that this invole
 * sorting. Sorting an array is N*Log(N) and since the complexity of the
 * solution using an unsorted_set is N then sorting an array becomes a bottle
 * neck.
 *
 * Since this is going to be sorted we can iterate over each number (a) and use
 * the two pointer approach where the pointers move closer to each other looking
 * for two pairs of numbers (b and c) that a + b + c = targetSum
 *
 * @param arr array containing N integers
 * @param targetSum target sum
 * @return vector<vector<int>>
 */
vector<vector<int>> triplets(vector<int> arr, int targetSum) {
  vector<vector<int>> result;
  int n = arr.size();

  for (int i = 0; i < n - 3; i++) {
    int j = i + 1;
    int k = n - 1;

    while (j < k) {
      int sum = arr[i] + arr[j] + arr[k];
      if (sum == targetSum) {
        result.push_back({arr[i], arr[j], arr[k]});
        j++;
        k--;
      } else if (sum > targetSum) {
        k--;
      } else {
        j++;
      }
    }
  }

  return result;
}

TEST_CASE("Triplets", "[levelup]") {
  vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
  vector<vector<int>> expected{
      {1, 2, 15}, {1, 8, 9}, {2, 7, 9}, {3, 6, 9},
      {3, 7, 8},  {4, 5, 9}, {4, 6, 8}, {5, 6, 7},
  };
  int S = 18;

  auto result = triplets(arr, S);

  REQUIRE(result == expected);
}
