#include <algorithm>
#include <gmpxx.h>
#include <numeric>
#include <vector>

namespace {

int orderMod(int d) {
  if (d % 2 == 0 || d % 5 == 0) {
    return 0;
  }
  mpz_class x{10};
  for (int i = 1; ; x *= 10, i++) {
    if (x % d == 1) {
      return i;
    }
  }
}

}

int p26() {
  std::vector<int> v(998);
  std::iota(v.begin(), v.end(), 2);
  std::transform(v.begin(), v.end(), v.begin(), orderMod);
  auto it = std::max_element(v.begin(), v.end());
  return 2 + std::distance(v.begin(), it);
}
