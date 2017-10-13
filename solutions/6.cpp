#include <array>
#include <numeric>

int p6() {
  std::array<int, 100> arr;
  std::iota(arr.begin(), arr.end(), 1);
  auto sum = std::accumulate(arr.begin(), arr.end(), 0);
  auto sum_of_squares = std::accumulate(
      arr.begin(),
      arr.end(),
      0,
      [](int total, int i) { return total + i * i; });
  return sum * sum - sum_of_squares;
}
