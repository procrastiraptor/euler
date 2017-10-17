#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

#include "lib/primes.h"

namespace {

auto trunc(int i) {
  std::vector<int> result;
  for (int k = i; k > 0; k /= 10) {
    result.push_back(k);
  }
  auto digits = static_cast<int>(std::log10(i));
  auto n = static_cast<int>(std::pow(10, digits));
  for (int k = i; k > 0; k %= n, n /= 10) {
    result.push_back(k);
  }
  return result;
}

bool truncatable(const std::vector<long>& primes, int i) {
  if (i < 10) {
    return false;
  }
  auto ts = trunc(i);
  return std::all_of(
      ts.begin(),
      ts.end(),
      [&primes](int t) {
        return std::binary_search(primes.begin(), primes.end(), t);
      });
}

}

int p37() {
  auto ps = primes::upTo(1'000'000);
  return std::accumulate(
      ps.begin(),
      ps.end(),
      0,
      [&ps](int total, auto p) {
        return total + (truncatable(ps, p) ? p : 0);
      });
}
