#include <algorithm>
#include <iostream>
#include <numeric>
#include <string_view>
#include <vector>

namespace {

auto split(std::string_view data) {
  std::vector<std::string_view> result;
  auto e = std::string_view::npos;
  for (auto s = data.find_first_of('"');
      s != std::string_view::npos;
      s = data.find_first_of('"', e + 1)) {
    e = data.find_first_of('"', s + 1);
    result.emplace_back(&data[s + 1], e - s - 1);
  }
  return result;
}

int nameScore(std::string_view name) {
  return std::accumulate(
      name.begin(),
      name.end(),
      0,
      [](int total, char c) { return total + (c - 'A' + 1); });
}

}

long p22() {
  std::string data;
  std::getline(std::cin, data, '\n');
  auto names = split(data);
  std::sort(names.begin(), names.end());
  return std::accumulate(
      names.begin(),
      names.end(),
      0L,
      [i=1](long total, auto n) mutable {
        return total + (nameScore(n) * i++);
      });
}
