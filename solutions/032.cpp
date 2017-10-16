#include <algorithm>
#include <numeric>
#include <set>

namespace {

int digits(char* dst, int src) {
  int written = 0;
  for (; src > 0; src /= 10, written++) {
    *dst++ = (src % 10) + '0';
  }
  return written;
}

bool pandigital(int a, int b) {
  std::array<char, 64> buf;
  int n = digits(buf.data(), a);
  n += digits(buf.data() + n, b);
  n += digits(buf.data() + n, a * b);
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
  constexpr int max = 10'000;
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
