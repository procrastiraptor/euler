#include <numeric>

#include "lib/primes.h"

long p10() {
  auto ps = primes::upTo(2'000'000);
  return std::accumulate(ps.begin(), ps.end(), 0L);
}
