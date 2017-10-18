#include <algorithm>
#include <array>
#include <string>
#include <vector>

#include "lib/permutations.h"

int p52() {
  constexpr std::array<int, 5> ns = { 2, 3, 4, 5, 6, };
  for (int i = 1; ; i++) {
    auto ps = permutations(std::to_string(i));
    if (ps.size() < 6) {
      continue;
    }
    std::vector<int> v(ps.size());
    std::transform(
       ps.begin(),
       ps.end(),
       v.begin(),
       [](const auto& s) { return std::stoi(s); });
    if (std::all_of(ns.begin(), ns.end(), [&v, i](int n) {
            return std::find(v.begin(), v.end(), n * i) != v.end();
          })) {
      return i;
    }
  }
}
