#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

#include "lib/primes.h"

namespace {

int multiplicity(int f, int n) {
  int result = 0;
  for (int d = f; n % d == 0; d *= f, result++) {}
  return result;
}

int numDivisors(int n) {
  if (n == 1) {
    return 1;
  }
  auto fs = primes::factorsOf(n);
  if (fs.empty()) {
    return 2;
  }
  std::vector<int> mult(fs.size());
  std::transform(
      fs.begin(),
      fs.end(),
      mult.begin(),
      [n](int f) { return 1 + multiplicity(f, n); });
  return std::accumulate(mult.begin(), mult.end(), 1, std::multiplies<int>{});
}

}

int p12() {
  for (int n = 1, i = 1; ; i++, n += i) {
    if (numDivisors(n) > 500) {
      return n;
    }
  }
}
