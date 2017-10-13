#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

namespace {

template<class It>
long product(It begin, It end) {
  return std::accumulate(
      begin,
      end,
      1L,
      [](long total, char c) { return total * (c - '0'); });
}

}

long p8() {
  constexpr size_t productLength = 13;
  std::ostringstream os;
  os << std::cin.rdbuf();
  auto number = os.str();
  auto it = std::remove(number.begin(), number.end(), '\n');
  number.erase(it, number.end());
  std::vector<long> prods(number.size() - productLength);
  std::transform(
      number.begin(),
      number.end() - productLength,
      prods.begin(),
      [](char& c) { return product(&c, &c + productLength); });
  return *std::max_element(prods.begin(), prods.end());
}
