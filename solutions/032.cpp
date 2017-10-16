#include <algorithm>
#include <cstdio>
#include <numeric>
#include <set>

namespace {

bool pandigital(int a, int b) {
  std::array<char, 10> buf;
  int n = std::snprintf(buf.data(), buf.size(), "%d%d%d", a, b, a * b);
  if (n != 9) {
    return false;
  }
  auto s = buf.begin();
  auto e = s + 9;
  std::sort(s, e);
  return std::equal(s, e, "123456789");
}

}

int p32() {
  constexpr int max = 5'000;
  std::set<int> prods;
  for (int a = 0; a < max; a++) {
    for (int b = a; b < max; b++) {
      if (pandigital(a, b)) {
        prods.insert(a * b);
      }
    }
  }
  return std::accumulate(prods.begin(), prods.end(), 0);
}
