#include <gmpxx.h>

int p25() {
  mpz_class a{1};
  mpz_class b{1};
  for (int i = 3; ; i++) {
    a += b;
    swap(a, b);
    if (b.get_str().size() == 1000) {
      return i;
    }
  }
}
