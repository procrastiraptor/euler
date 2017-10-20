#pragma once

#include <optional>
#include <string_view>
#include <vector>

namespace matsearch {

struct Cell {
  int val;
  mutable std::optional<int> minPath;

  explicit Cell(int i) : val(i), minPath() {}
};

using Matrix = std::vector<Cell>;

Matrix split(std::string_view sv);

}
