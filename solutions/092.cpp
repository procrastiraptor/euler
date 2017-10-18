#include <numeric>
#include <string>

namespace {

int squareSum(int i) {
  auto s = std::to_string(i);
  return std::accumulate(
      s.begin(),
      s.end(),
      0,
      [](int total, char c) { return total + (c - '0') * (c - '0'); });
}

bool eightyNine(int i) {
  for (int n = i; n > 1; n = squareSum(n)) {
    if (n == 89) {
      return true;
    }
  }
  return false;
}

}

int p92() {
  int result = 0;
  for (int i = 1; i < 10'000'000; i++) {
    result += eightyNine(i);
  }
  return result;
}
