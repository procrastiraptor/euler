#include <algorithm>
#include <array>
#include <functional>
#include <string>
#include <numeric>

#include "lib/permutations.h"

namespace {

std::string concat(const std::array<int, 10>& arr, size_t n) {
  return std::accumulate(
      arr.begin(),
      arr.begin() + n,
      std::string{},
      [](auto s, int v) { return s + std::to_string(v); });
}

bool concatProduct(const std::string& s) {
  for (size_t i = 1; i < s.size(); i++) {
    int base = std::stod(s.substr(0, i));
    size_t n = s.size() / i;
    std::array<int, 10> arr;
    for (size_t j = 0; j < n; j++) {
      arr[j] = base * (j + 1);
    }
    if (concat(arr, n) == s) {
      return true;
    }
  }
  return false;
}

}

int p38() {
  auto is = permutations("123456789");
  auto it = std::remove_if(is.begin(), is.end(), std::not_fn(concatProduct));
  return std::stod(*std::max_element(is.begin(), it));
}
