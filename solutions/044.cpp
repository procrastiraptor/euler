#include <algorithm>
#include <vector>

namespace {

auto pentagonal(int n) {
  std::vector<long> result(n);
  for (int i = 1; i < n; i++) {
    result[i] = i * (3 * i - 1) / 2;
  }
  return result;
}

bool check(const std::vector<long>& ps, long i) {
  return std::binary_search(ps.begin(), ps.end(), i);
}

}

int p44() {
  auto ps = pentagonal(5'000);
  for (auto diff : ps) {
    for (size_t i = 1; i < ps.size(); i++) {
      auto a = ps[i];
      for (size_t j = i + 1; j < ps.size(); j++) {
        auto b = ps[j];
        if (b < a) {
          continue;
        }
        if (b - a == diff && check(ps, b + a)) {
          return diff;
        } else if (b - a > diff) {
          break;
        }
      }
    }
  }
  return 0;
}
