#include <algorithm>
#include <array>
#include <numeric>

int p5() {
  std::array<int, 20> ds;
  std::iota(ds.begin(), ds.end(), 1);
  for (int i = 20; ; i += 20) {
    if (std::all_of(ds.begin(), ds.end(), [i](int d) { return i % d == 0; })) {
      return i;
    }
  }
}
