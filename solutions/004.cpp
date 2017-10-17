#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

#include "lib/palindrome.h"

int p4() {
  std::vector<int> is(900);
  std::iota(is.begin(), is.end(), 100);
  std::vector<int> prods;
  prods.reserve(is.size() * is.size());
  for (int i : is) {
    std::transform(
        is.begin(),
        is.end(),
        std::back_inserter(prods),
        [i](int j) { return i * j; });
  }
  auto it = std::remove_if(
      prods.begin(),
      prods.end(),
      [](int i) { return !palindrome(std::to_string(i)); });
  return *std::max_element(prods.begin(), it);
}
