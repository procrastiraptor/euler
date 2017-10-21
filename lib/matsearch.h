#pragma once

#include <istream>
#include <optional>
#include <vector>

namespace matsearch {

struct Cell {
  int val;
  mutable std::optional<int> minPath;

  explicit Cell(int i) : val(i), minPath() {}
};

using Matrix = std::vector<Cell>;

std::istream& operator>>(std::istream& in, Matrix& m);

}
