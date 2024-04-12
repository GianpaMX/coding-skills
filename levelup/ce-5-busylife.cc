#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

int busyLife(vector<pair<int, int>> activities) {
  sort(activities.begin(), activities.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) {
         return a.first > b.first ||
                a.first == b.first && a.second - a.first < b.second - b.first;
       });

  int count = 1;
  int lastStartTime = activities[0].first;
  for (auto activity : activities) {
    if (activity.second <= lastStartTime) {
      count++;
      lastStartTime = activity.first;
    }
  }

  return count;
}

TEST_CASE("Busy Life Test 1", "[levelup]") {
  vector<pair<int, int>> activities{

      make_pair(7, 9),

      make_pair(0, 10),

      make_pair(4, 5),

      make_pair(8, 9),

      make_pair(4, 10),

      make_pair(5, 7),

      make_pair(11, 12)

  };
  int expected = 4;

  auto result = busyLife(activities);

  REQUIRE(result == expected);
}

TEST_CASE("Busy Life Test 2", "[levelup]") {
  vector<pair<int, int>> activities{

      make_pair(7, 9),

      make_pair(0, 10),

      make_pair(4, 5),

      make_pair(8, 9),

      make_pair(4, 10),

      make_pair(5, 7)

  };
  int expected = 3;

  auto result = busyLife(activities);

  REQUIRE(result == expected);
}

TEST_CASE("Busy Life Test 3", "[levelup]") {
  vector<pair<int, int>> activities{

      make_pair(1, 7),

      make_pair(5, 8),

      make_pair(7, 8),

      make_pair(1, 8)

  };
  int expected = 2;

  auto result = busyLife(activities);

  REQUIRE(result == expected);
}
