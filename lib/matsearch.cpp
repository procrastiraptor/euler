#include "matsearch.h"

#include <cmath>

namespace matsearch {

namespace {

void setupPointers(Matrix& m) {
  auto dim = static_cast<size_t>(std::sqrt(m.size()));
  for (size_t i = 0; i < dim; i++) {
    for (size_t j = 0; j < dim; j++) {
      auto idx = i * dim + j;
      auto& c = m[idx];
      c.up = i > 0 ? &m[idx - dim] : nullptr;
      c.left = j > 0 ? &m[idx - 1] : nullptr;
      c.down = i < dim - 1 ? &m[idx + dim] : nullptr;
      c.right = j < dim - 1 ? &m[idx + 1] : nullptr;
    }
  }
}

}

std::istream& operator>>(std::istream& in, Matrix& m) {
  int i;
  while (in >> i) {
    m.emplace_back(i);
    in.get();  // skip ',' or newline
  }
  setupPointers(m);
  return in;
}

}
