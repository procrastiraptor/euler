#include "split.h"

std::vector<std::string_view> split(std::string_view data) {
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
