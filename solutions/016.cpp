#include <gmpxx.h>

#include "lib/digitsum.h"

int p16() {
  mpz_class z = 1;
  for (int i = 0; i < 1000; i++) {
    z *= 2;
  }
  return digitSum(z.get_str());
}
