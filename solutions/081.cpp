#include <cmath>
#include <iostream>
#include <limits>

#include "lib/matsearch.h"

namespace {

auto minPath(const matsearch::Matrix& m, const matsearch::Cell& c) {
  if (c.minPath.has_value()) {
    return c.minPath.value();
  }
  constexpr auto max = std::numeric_limits<int>::max();
  auto right = c.right ? minPath(m, *c.right) : max;
  auto down = c.down ? minPath(m, *c.down) : max;
  c.minPath = c.val + std::min(right, down);
  return c.minPath.value();
}

}

int p81() {
  matsearch::Matrix m;
  std::cin >> m;
  if (m.empty()) {
    return 0;
  } else {
    m.back().minPath = m.back().val;
  }
  return minPath(m, m.front());
}
