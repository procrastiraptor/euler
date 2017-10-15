#include <gmpxx.h>

#include "lib/digitsum.h"

int p20() {
  mpz_class z{1};
  for (int i = 1; i <= 100; i++) {
    z *= i;
  }
  return digitSum(z.get_str());
}
