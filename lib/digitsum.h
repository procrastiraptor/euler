#pragma once

#include <numeric>
#include <string_view>

inline int digitSum(std::string_view s) {
  return std::accumulate(
      s.begin(),
      s.end(),
      0,
      [](int total, char c) { return total + (c - '0'); });
}
