#include "primes.h"

#include <algorithm>
#include <cmath>

using plist = std::vector<long>;

namespace primes {

namespace {

long next(const plist& ps) {
  if (ps.empty()) {
    return 2;
  } else if (ps.back() == 2) {
    return 3;
  }
  for (auto i = ps.back() + 2; ; i += 2) {
    auto it = std::find_if(
        ps.begin(), ps.end(), [i](long p) { return p * p > i; });
    if (std::all_of(ps.begin(), it, [i](long p) { return i % p != 0; })) {
      return i;
    }
  }
}

}

plist upTo(long v) {
  plist result;
  if (v < 2) {
    return result;
  }
  result.push_back(2);
  for (auto p = next(result); p <= v; p = next(result)) {
    result.push_back(p);
  }
  return result;
}

plist factorsOf(long v) {
  auto max = static_cast<long>(std::sqrt(v)) + 1;
  auto ps = upTo(max);
  plist result;
  auto it = std::remove_if(
      ps.begin(), ps.end(), [v](long p) { return v % p != 0; });
  ps.erase(it, ps.end());
  for (auto p : ps) {
    while (v % p == 0) { v /= p; }
  }
  if (v > 1) {
    ps.push_back(v);
  }
  return ps;
}

plist first(int n) {
  plist result;
  result.reserve(n);
  std::generate_n(
      std::back_inserter(result), n, [&result]() { return next(result); });
  return result;
}

}
