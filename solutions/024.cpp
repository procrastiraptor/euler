#include <algorithm>
#include <string>
#include <vector>

namespace {

std::vector<std::string> permutations(std::string s) {
  if (s.size() == 1) {
    return std::vector<std::string>({s});
  }
  char c = s.back();
  s.pop_back();
  std::vector<std::string> result;
  for (const auto& p : permutations(std::move(s))) {
    for (size_t i = 0; i <= p.size(); i++) {
      std::string n(p);
      n.insert(i, 1, c);
      result.emplace_back(std::move(n));
    }
  }
  return result;
}

}

long p24() {
  auto ps = permutations("0123456789");
  std::sort(ps.begin(), ps.end());
  return std::stol(ps.at(999'999));
}
