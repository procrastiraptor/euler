#include <array>
#include <numeric>
#include <string>

constexpr std::array<size_t, 7> digits = {
  1, 10, 100, 1000, 10'000, 100'000, 1'000'000, };

int p40() {
  std::string s;
  for (int i = 1; s.size() < digits.back(); i++) {
    s += std::to_string(i);
  }
  return std::accumulate(
      digits.begin(),
      digits.end(),
      1,
      [&s](int total, auto d) { return total * (s[d - 1] - '0'); });
}
