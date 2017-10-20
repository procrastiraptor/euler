#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>

#include "lib/matsearch.h"

namespace {

auto minPath(const matsearch::Matrix& m, size_t idx) {
  if (idx >= m.size()) {
    return 0;
  }
  const auto& c = m[idx];
  if (c.minPath.has_value()) {
    return c.minPath.value();
  }
  auto dim = static_cast<size_t>(std::sqrt(m.size()));
  auto i = idx / dim;
  auto j = idx % dim;
  constexpr auto max = std::numeric_limits<int>::max();
  auto right = j < dim - 1 ? minPath(m, idx + 1) : max;
  auto down = i < dim - 1 ? minPath(m, idx + dim) : max;
  c.minPath = c.val + std::min(right, down);
  return c.minPath.value();
}

}

int p81() {
  std::ostringstream os;
  os << std::cin.rdbuf();
  auto m = matsearch::split(os.str());
  if (m.empty()) {
    return 0;
  } else {
    m.back().minPath = m.back().val;
  }
  return minPath(m, 0);
}
