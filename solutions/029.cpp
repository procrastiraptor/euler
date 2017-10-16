#include <gmpxx.h>
#include <set>

int p29() {
  std::set<mpz_class> s;
  for (int a = 2; a <= 100; a++) {
    for (int b = 2; b <= 100; b++) {
      mpz_class z(1);
      for (int i = 0; i < b; i++) {
        z *= a;
      }
      s.insert(z);
    }
  }
  return s.size();
}
