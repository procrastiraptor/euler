#include <algorithm>
#include <vector>

#include "lib/primes.h"

namespace {

bool goldbach(const std::vector<long>& primes, int v) {
  if (std::binary_search(primes.begin(), primes.end(), v)) {
    return true;
  }
  for (auto p : primes) {
    for (int i = 1, sum = p; sum <= v; sum = p + (2 * i * i), i++) {
      if (sum == v) {
        return true;
      }
    }
  }
  return false;
}

}

int p46() {
  auto ps = primes::upTo(5'000);
  for (int i = 9; ; i += 2) {
    if (!goldbach(ps, i)) {
      return i;
    }
  }
}
