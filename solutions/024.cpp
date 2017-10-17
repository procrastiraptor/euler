#include <algorithm>
#include <string>
#include <vector>

#include "lib/permutations.h"

long p24() {
  auto ps = permutations("0123456789");
  std::sort(ps.begin(), ps.end());
  return std::stol(ps.at(999'999));
}
