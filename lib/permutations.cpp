#include "permutations.h"

std::vector<std::string> permutations(std::string s) {
  if (s.size() == 1) {
    return std::vector<std::string>({s});
  }
  char c = s.back();
  s.pop_back();
  auto ps = permutations(std::move(s));
  std::vector<std::string> result;
  result.reserve(ps.size() * (ps.front().size() + 1));
  for (const auto& p : ps) {
    for (size_t i = 0; i <= p.size(); i++) {
      result.emplace_back(p);
      result.back().insert(i, 1, c);
    }
  }
  return result;
}
