#include <algorithm>

#include "lib/primes.h"

int p3() {
  auto fs = primes::factorsOf(600'851'475'143);
  return *std::max_element(fs.begin(), fs.end());
}
