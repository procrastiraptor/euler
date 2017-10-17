#include <algorithm>
#include <array>

long p45() {
  std::array<long, 3> ns = { 3, 5, 6, };
  std::array<long, 3> is = { 2, 2, 2, };
  while (ns[0] == 40755 || ns[0] != ns[1] || ns[1] != ns[2]) {
    // 40755 is the minimal value where all are equal, but we want the value
    // after that.
    auto min = std::min_element(ns.begin(), ns.end());
    auto idx = std::distance(ns.begin(), min);
    auto n = ++is[idx];
    switch (idx) {
    case 0:  // triangle
      ns[idx] = n * (n + 1) / 2;
      break;
    case 1:  // pentagon
      ns[idx] = n * (3 * n - 1) / 2;
      break;
    case 2:  // hexagon
      ns[idx] = n * (2 * n - 1);
      break;
    }
  }
  return ns.front();
}
