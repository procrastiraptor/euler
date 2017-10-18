#include <gmpxx.h>

namespace {

struct Fraction {
  mpz_class n, d;

  Fraction(mpz_class a, mpz_class b) : n(a), d(b) {}
};

Fraction inc(Fraction f) {
  return { f.n + f.d, f.d };
}

Fraction inverse(Fraction f) {
  return { f.d, f.n };
}

Fraction expand(Fraction f) {
  return inc(inverse(inc(f)));
}

bool check(Fraction f) {
  return f.n.get_str().size() > f.d.get_str().size();
}

}

int p57() {
  int result = 0;
  Fraction f = { 3, 2 };
  for (int i = 0; i < 1000; i++, f = expand(f)) {
    result += check(f);
  }
  return result;
}
