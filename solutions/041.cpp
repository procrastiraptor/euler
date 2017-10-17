#include <algorithm>
#include <string>

#include "lib/primes.h"

namespace {

bool pandigital(int i) {
  auto s = std::to_string(i);
  std::sort(s.begin(), s.end());
  return std::equal(s.begin(), s.end(), "123456789");
}

}

int p41() {
  auto ps = primes::upTo(10'000'000);
  auto it = std::remove_if(
      ps.begin(),
      ps.end(),
      [](long p) { return !pandigital(p); });
  return *(it - 1);
}
