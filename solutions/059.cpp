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

}

int p59() {
  std::string data;
  std::getline(std::cin, data, '\n');
  auto input = read(data);

  std::array<char, 'z' - 'a' + 1> lc;
  std::iota(lc.begin(), lc.end(), 'a');
  for (char a : lc) {
    for (char b : lc) {
      for (char c : lc) {
        if (auto decoded = tr(input, { a, b, c, }); plaintext(decoded)) {
          return std::accumulate(decoded.begin(), decoded.end(), 0);
        }
      }
    }
  }
  return 0;
}
