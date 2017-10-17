#include <algorithm>
#include <vector>

#include "lib/primes.h"

namespace {

int primeSum(const std::vector<long>& primes, int v) {
  auto a = primes.begin();
  auto sum = *a;
  for (auto b = a + 1; b < primes.end() && *b < v; ++b) {
    while (sum > v) {
      sum -= *a++;
    }
    if (sum < v) {
      sum += *b;
    } else {
      return std::distance(a, b);
    }
  }
  return 0;
}

}

int p50() {
  auto ps = primes::upTo(1'000'000);
  return *std::max_element(
      ps.begin(),
      ps.end(),
      [&ps](long a, long b) { return primeSum(ps, a) < primeSum(ps, b); });
}
