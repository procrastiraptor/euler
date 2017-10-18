#include <algorithm>
#include <gmpxx.h>

#include "lib/palindrome.h"

namespace {

mpz_class reverseAndAdd(mpz_class i) {
  auto s = i.get_str();
  std::reverse(s.begin(), s.end());
  auto n = s.find_first_not_of('0');
  return i + mpz_class{s.substr(n)};
}

bool lychrel(int n) {
  mpz_class z{n};
  for (int i = 0; i < 50; i++) {
    z = reverseAndAdd(z);
    if (palindrome(z.get_str())) {
      return false;
    }
  }
  return true;
}

}

int p55() {
  int result = 0;
  for (int i = 1; i < 10'000; i++) {
    result += lychrel(i);
  }
  return result;
}
