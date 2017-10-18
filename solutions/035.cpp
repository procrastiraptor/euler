#include <algorithm>
#include <string>
#include <vector>

#include "lib/primes.h"

namespace {

template<class C>
auto rotations(C c) {
  std::vector<C> result;
  for (size_t i = 1; i < c.size(); i++) {
    std::rotate(c.begin(), c.begin() + 1, c.end());
    result.push_back(c);
  }
  return result;
}

bool circular(const std::vector<long>& primes, int i) {
  auto rs = rotations(std::to_string(i));
  return std::all_of(
      rs.begin(),
      rs.end(),
      [&primes](const auto& s) {
        return std::binary_search(primes.begin(), primes.end(), std::stol(s));
      });
}

}

int p35() {
  auto ps = primes::upTo(1'000'000);
  return std::count_if(
      ps.begin(),
      ps.end(),
      [&ps](auto p) { return circular(ps, p); });
}
