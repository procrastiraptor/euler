#include <cmath>
#include <iostream>
#include <limits>
#include <optional>
#include <sstream>
#include <string_view>
#include <vector>

namespace {

struct Cell {
  int val;
  mutable std::optional<int> minPath;

  explicit Cell(int i) : val(i), minPath() {}
};

using Matrix = std::vector<Cell>;

auto minPath(const Matrix& m, size_t idx) {
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

auto split(std::string_view sv) {
  Matrix result;
  int curr = 0;
  for (char c : sv) {
    if (std::isdigit(c)) {
      curr = curr * 10 + (c - '0');
    } else {
      result.emplace_back(curr);
      curr = 0;
    }
  }
  if (!result.empty()) {
    result.back().minPath = result.back().val;
  }
  return result;
}

}

int p81() {
  std::ostringstream os;
  os << std::cin.rdbuf();
  auto m = split(os.str());
  return minPath(m, 0);
}
