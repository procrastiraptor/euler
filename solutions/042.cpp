#include <algorithm>
#include <iostream>
#include <numeric>
#include <string_view>

#include "lib/split.h"

namespace {

int score(std::string_view sv) {
  return std::accumulate(
      sv.begin(),
      sv.end(),
      0,
      [](int total, char c) { return total + (c - 'A' + 1); });
}

bool triangle(std::string_view sv) {
  auto s = score(sv);
  for (int i = 1, n = 2; ; i += n, n++) {
    if (i == s) {
      return true;
    } else if (i > s) {
      return false;
    }
  }
}

}

int p42() {
  std::string data;
  std::getline(std::cin, data, '\n');
  auto words = split(data);
  return std::count_if(words.begin(), words.end(), triangle);
}
