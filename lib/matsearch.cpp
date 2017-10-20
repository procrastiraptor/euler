#include "matsearch.h"

namespace matsearch {

Matrix split(std::string_view sv) {
  Matrix result;
  int curr = 0;
  for (char c : sv) {
    if (std::isdigit(c)) {
      curr = curr * 10 + (c - '0');
    } else {
      result.emplace_back(curr);
      curr = 0;
    }
  }
  if (!result.empty()) {
    result.back().minPath = result.back().val;
  }
  return result;
}

}
