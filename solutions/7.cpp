#include "lib/primes.h"

int p7() {
  return primes::first(10'001).back();
}
