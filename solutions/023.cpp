#include <algorithm>
#include <functional>
#include <numeric>
#include <unordered_set>
#include <vector>

namespace {

constexpr bool abundant(int n) {
  int sum = 1;
  for (int i = 2; i < n / 2 + 1; i++) {
    sum += (n % i == 0 ? i : 0);
  }
  return sum > n;
}

}

int p23() {
  constexpr int max = 28'123;
  std::vector<int> is(max);
  std::iota(is.begin(), is.end(), 1);
  auto it = std::remove_if(is.begin(), is.end(), std::not_fn(abundant));
  is.erase(it, is.end());
  std::unordered_set<int> sums;
  for (int i : is) {
    for (int j : is) {
      sums.insert(i + j);
    }
  }
  int result = 0;
  for (int i = 0; i <= max; i++) {
    if (auto it = sums.find(i); it == sums.end()) {
      result += i;
    }
  }
  return result;
}
