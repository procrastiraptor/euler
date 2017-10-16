#include <cmath>
#include <numeric>
#include <string>

namespace {

int digitPowerSum(int i) {
  auto s = std::to_string(i);
  return std::accumulate(
      s.begin(),
      s.end(),
      0,
      [](int total, char c) { return total + std::pow(c - '0', 5); });
}

}

int p30() {
  int result = 0;
  for (int i = 10; i < 500'000; i++) {
    if (digitPowerSum(i) == i) {
      result += i;
    }
  }
  return result;
}
