#include <algorithm>
#include <iostream>
#include <numeric>
#include <string_view>

#include "lib/split.h"

namespace {

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
