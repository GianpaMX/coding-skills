#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

pair<int, int> minDiff(vector<int> a, vector<int> b) {
  sort(b.begin(), b.end());

  pair<int, int> result;

  int diff = INT_MAX;
  for (auto a_i : a) {
    auto b_j = lower_bound(b.begin(), b.end(), a_i) - b.begin();

    if (b_j >= 1 && a_i - b[b_j - 1] < diff) {
      diff = a_i - b[b_j - 1];
      result.first = a_i;
      result.second = b[b_j - 1];
    }

    if (b_j != b.size() && b[b_j] - a_i < diff) {
      diff = b[b_j] - a_i;
      result.first = a_i;
      result.second = b[b_j];
    }
  }

  return result;
}

TEST_CASE("Minimum Difference Test 1", "[levelup]") {
  vector<int> a{23, 5, 10, 17, 30};
  vector<int> b{26, 134, 135, 14, 19};
  pair<int, int> expected = make_pair(17, 19);

  auto result = minDiff(a, b);

  REQUIRE(result == expected);
}

TEST_CASE("Minimum Difference Test 2", "[levelup]") {
  vector<int> a{23, 5, 10, 117, 5, 30};
  vector<int> b{26, 134, 135, 124, 10, 19, 100, 120};
  pair<int, int> expected = make_pair(10, 10);

  auto result = minDiff(a, b);

  REQUIRE(result == expected);
}
