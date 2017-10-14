#include <gmpxx.h>
#include <numeric>
#include <string_view>

namespace {

auto digitSum(std::string_view s) {
  return std::accumulate(
      s.begin(),
      s.end(),
      0,
      [](int total, char c) { return total + (c - '0'); });
}

}

int p16() {
  mpz_class z = 1;
  for (int i = 0; i < 1000; i++) {
    z *= 2;
  }
  return digitSum(z.get_str());
}
