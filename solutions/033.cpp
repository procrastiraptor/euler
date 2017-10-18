#include <array>
#include <functional>
#include <numeric>
#include <vector>

namespace {

struct Fraction {
  int n, d;

  Fraction() : n(0), d(1) {}
  Fraction(int a, int b) : n(a), d(b) {}
};

bool operator==(Fraction a, Fraction b) {
  return a.n * b.d == b.n * a.d;
}

Fraction operator*(Fraction a, Fraction b) {
  return { a.n * b.n, a.d * b.d };
}

Fraction simplify(Fraction f) {
  int n1 = f.n / 10, n2 = f.n % 10;
  int d1 = f.d / 10, d2 = f.d % 10;
  if (n2 == d2 && n2 != 0) {
    return { n1, d1 };
  } else if (n2 == d1) {
    return { n1, d2 };
  } else if (n1 == d1) {
    return { n2, d2 };
  } else if (n1 == d2) {
    return { n2, d1 };
  }
  return f;
}

auto cands() {
  std::vector<Fraction> result;
  result.reserve(90 * 90);
  for (int n = 10; n < 100; n++) {
    for (int d = n + 1; d < 100; d++) {
      result.emplace_back(n, d);
    }
  }
  return result;
}

}

int p33() {
  std::array<Fraction, 4> result;
  auto cs = cands();
  std::copy_if(cs.begin(), cs.end(), result.begin(), [](auto c) {
      auto s = simplify(c);
      return (s.n != c.n || s.d != c.d) && s == c;
    });
  auto p = std::accumulate(
      result.begin(),
      result.end(),
      Fraction{ 1, 1 },
      std::multiplies<Fraction>{});
  return p.d / std::gcd(p.n, p.d);
}
