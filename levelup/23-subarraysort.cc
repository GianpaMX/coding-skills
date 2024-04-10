#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

using namespace std;

bool isOutOfOrder(vector<int> arr, int i);

vector<int> subarraySort(vector<int> arr) {
  int n = arr.size();

  vector<int> result(2, -1);

  int smallest = INT_MAX;
  int largest = INT_MIN;
  for (int i = 1; i < n - 1; i++) {
    if (isOutOfOrder(arr, i)) {
      smallest = min(smallest, arr[i]);
      largest = max(largest, arr[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (smallest < arr[i]) {
      result[0] = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (largest > arr[i]) {
      result[1] = i;
      break;
    }
  }

  return result;
}

bool isOutOfOrder(vector<int> arr, int i) {
  if (i == 0) {
    return arr[i] > arr[i + 1];
  }
  if (i == arr.size() - 1) {
    return arr[i] < arr[i - 1];
  }

  return arr[i - 1] > arr[i] || arr[i + 1] < arr[i];
}

TEST_CASE("Subarray Sort", "[levelup]") {
  vector<int> arr{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
  vector<int> expected{5, 7};

  auto result = subarraySort(arr);

  REQUIRE(result == expected);
}
