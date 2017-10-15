#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <vector>

namespace {

std::array<const char*, 10> digits = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine",
};

std::array<const char*, 10> teens = {
  "ten",
  "eleven",
  "twelve",
  "thirteen",
  "fourteen",
  "fifteen",
  "sixteen",
  "seventeen",
  "eighteen",
  "nineteen",
};

std::array<const char*, 8> tens = {
  "twenty",
  "thirty",
  "forty",
  "fifty",
  "sixty",
  "seventy",
  "eighty",
  "ninety",
};

std::string say(size_t i) {
  if (i < 1) {
    return "";
  } else if (i >= 1000) {
    return "onethousand";
  }
  std::string result;
  if (auto hundreds = i / 100; hundreds > 0) {
    result += digits[hundreds] + std::string{"hundred"};
  }
  if (i % 100 == 0) {
    return result;
  } else if (i / 100 > 0) {
    result += "and";
  }
  if (auto ts = (i % 100) / 10; ts > 1) {
    result += tens[ts - 2];
  } else if (ts == 1) {
    result += teens[i % 10];
    return result;
  }
  if (auto ones = i % 10; ones > 0) {
    result += digits[ones];
  }
  return result;
}

}

int p17() {
  std::vector<int> v(1000);
  std::iota(v.begin(), v.end(), 1);
  return std::accumulate(
      v.begin(),
      v.end(),
      0,
      [](int total, int i) { return total + say(i).size(); });
}
