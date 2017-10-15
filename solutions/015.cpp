#include <gmpxx.h>

namespace {

mpz_class fact(int n) {
  mpz_class result = 1;
  for (int i = n; i > 1; i--) {
    result *= i;
  }
  return result;
}

long choose(int n, int k) {
  mpz_class d = fact(k) * fact(n - k);
  mpz_class res = fact(n) / d;
  return res.get_si();
}

}

long p15() {
  return choose(40, 20);
}
