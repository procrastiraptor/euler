#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <string_view>

#include "lib/permutations.h"

namespace {

constexpr std::array<int, 7> divisors = { 2, 3, 5, 7, 11, 13, 17 };

auto substrings(std::string_view sv) {
  std::array<int, divisors.size()> result;
  for (size_t i = 0; i < result.size(); i++) {
    result[i] = std::stod(std::string(sv.substr(i + 1, 3)));
  }
  return result;
}

bool divisible(std::string_view sv) {
  auto is = substrings(sv);
  return std::all_of(
      is.begin(),
      is.end(),
      [k=0](int i) mutable { return i % divisors[k++] == 0; });
}

}

long p43() {
  auto is = permutations("0123456789");
  auto it = std::remove_if(
      is.begin(),
      is.end(),
      [](const auto& s) { return !divisible(s); });
  return std::accumulate(
      is.begin(),
      it,
      0L,
      [](long total, const auto& s) { return total + std::stol(s); });
}
