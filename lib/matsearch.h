#pragma once

#include <istream>
#include <optional>
#include <vector>

namespace matsearch {

struct Cell {
  int val;
  mutable std::optional<int> minPath;
  Cell *up, *right, *down, *left;

  explicit Cell(int i)
    : val(i),
      minPath(),
      up(nullptr),
      right(nullptr),
      down(nullptr),
      left(nullptr) {}
};

using Matrix = std::vector<Cell>;

std::istream& operator>>(std::istream& in, Matrix& m);

}
