#include <gmpxx.h>
#include <string>

long p48() {
  mpz_class sum = 0;
  for (int i = 1; i <= 1000; i++) {
    mpz_class power = 1;
    for (int j = 0; j < i; j++) {
      power *= i;
    }
    sum += power;
  }
  auto s = sum.get_str();
  return std::stol(s.substr(s.size() - 10));
}
