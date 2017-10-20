#include <algorithm>
#include <array>
#include <cmath>
#include <numeric>
#include <vector>

#include "lib/primes.h"

namespace {

constexpr int cat(int a, int b) {
  auto digits = 1 + static_cast<int>(std::log10(b));
  return a * std::pow(10, digits) + b;
}

bool ok(const std::vector<int>& ps, int v) {
  return std::all_of(
      ps.begin(),
      ps.end(),
      [v](int p) { return primes::is(cat(p, v)) && primes::is(cat(v, p)); });
}

}

int p60() {
  auto ps = primes::upTo(10'000);
  for (int a : ps) {
    std::vector<int> res{a};
    for (int v : ps) {
      if (ok(res, v)) {
        res.push_back(v);
      }
      if (res.size() == 5) {
        return std::accumulate(res.begin(), res.end(), 0);
      }
    }
  }
  return 0;
}
