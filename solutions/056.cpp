#include <gmpxx.h>

#include "lib/digitsum.h"

int p56() {
  int max = 0;
  for (int a = 1; a < 100; a++) {
    mpz_class z{1};
    for (int b = 1; b < 100; b++) {
      z *= a;
      auto s = digitSum(z.get_str());
      max = std::max(max, s);
    }
  }
  return max;
}
