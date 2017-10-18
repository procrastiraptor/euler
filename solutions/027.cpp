#include "lib/primes.h"

namespace {

int quadraticPrimes(int a, int b) {
  for (int i = 1; ; i++) {
    if (!primes::is(i * i + a * i + b)) {
      return i;
    }
  }
}

}

long p27() {
  int max = 0;
  int prod = 0;
  for (int b : primes::upTo(1000)) {
    for (int a = -999; a < 1000; a++) {
      int ps = quadraticPrimes(a, b);
      if (ps > max) {
        max = ps;
        prod = a * b;
      }
    }
  }
  return prod;
}
