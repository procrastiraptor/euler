#include "lib/primes.h"

namespace {

int quadraticPrimes(int a, int b) {
  for (int i = 0; ; i++) {
    if (!primes::is(i * i + a * i + b)) {
      return i;
    }
  }
}

}

long p27() {
  int max = 0;
  int prod = 0;
  for (int a = -999; a < 1000; a++) {
    for (int b = -1000; b <= 1000; b++) {
      int ps = quadraticPrimes(a, b);
      if (ps > max) {
        max = ps;
        prod = a * b;
      }
    }
  }
  return prod;
}
