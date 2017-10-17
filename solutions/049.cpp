#include <algorithm>
#include <string>
#include <vector>

#include "lib/primes.h"

namespace {

bool check(const std::vector<long>& primes, const std::string& digits, int i) {
  if (!std::binary_search(primes.begin(), primes.end(), i)) {
    return false;
  }
  auto s = std::to_string(i);
  std::sort(s.begin(), s.end());
  return s == digits;
}

}

long p49() {
  auto ps = primes::upTo(10'000);
  auto it = std::remove_if(
      ps.begin(), ps.end(), [](long p) { return p < 1000; });
  ps.erase(it, ps.end());
  for (long a : ps) {
    if (a == 1487) {
      continue;  // This is the example given in the problem.
    } 
    auto digits = std::to_string(a);
    std::sort(digits.begin(), digits.end());
    for (int d = 1; d < 4500; d++) {
      long b = a + d;
      long c = b + d;
      if (check(ps, digits, b) && check(ps, digits, c)) {
        return a * 100'000'000 + b * 10'000 + c;
      }
    }
  }
  return 0;
}
