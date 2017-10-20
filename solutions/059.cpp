#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <string_view>

namespace {

using Key = std::array<char, 3>;

std::string tr(std::string_view input, Key key) {
  std::string res;
  res.reserve(input.size());
  std::transform(
      input.begin(),
      input.end(),
      std::back_inserter(res),
      [key,i=0](char c) mutable {
        return c ^ key[i++ % std::tuple_size<Key>::value];
      });
  return res;
}

std::string read(std::string_view data) {
  std::string res{'\0'};
  res.reserve(data.size());
  for (char c : data) {
    if (c == ',') {
      res.push_back('\0');
    } else {
      res.back() = res.back() * 10 + (c - '0');
    }
  }
  return res;
}

bool plaintext(std::string_view text) {
  return text.find(" the ") != std::string_view::npos;
}

int sum(std::string_view sv) {
  return std::accumulate(sv.begin(), sv.end(), 0);
}

}

int p59() {
  std::string data;
  std::getline(std::cin, data, '\n');
  auto input = read(data);
  for (char a = 'a'; a <= 'z'; a++) {
    for (char b = 'a'; b <= 'z'; b++) {
      for (char c = 'a'; c <= 'z'; c++) {
        auto decoded = tr(input, { a, b, c, });
        if (plaintext(decoded)) {
          return sum(decoded);
        }
      }
    }
  }
  return 0;
}
