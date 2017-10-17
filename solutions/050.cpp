#include <algorithm>
#include <vector>

#include "lib/primes.h"

namespace {

int primeSum(const std::vector<long>& primes, int v) {
  for (const auto& p : primes) {
    auto ptr = &p;
    for (int i = 0, sum = 0; sum <= v; sum += ptr[i], i++) {
      if (sum == v) {
        return i;
      }
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
