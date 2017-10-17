#include <array>
#include <numeric>

namespace {

constexpr int fact(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

constexpr std::array<int, 10> facts = {
  fact(0), fact(1), fact(2), fact(3), fact(4),
  fact(5), fact(6), fact(7), fact(8), fact(9),
};

int digitSum(int i) {
  auto s = std::to_string(i);
  return std::accumulate(
      s.begin(),
      s.end(),
      0L,
      [](int total, char c) { return total + facts[c - '0']; });
}

}

int p34() {
  int result = 0;
  for (int i = 10; i < 50'000; i++) {
    result += (i == digitSum(i) ? i : 0);
  }
  return result;
}
