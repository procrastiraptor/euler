#include <algorithm>
#include <array>

namespace {

constexpr size_t max = 1'000'000;

std::array<int, max> lengths;

int calcLength(size_t i) {
  if (i < max && lengths[i] > 0) {
    return lengths[i];
  }
  int result = 1;
  if (i % 2 == 0) {
    result += calcLength(i / 2);
  } else {
    result += calcLength(3 * i + 1);
  }
  if (i < max) {
    lengths[i] = result;
  }
  return result;
}

}

int p14() {
  lengths.fill(0);
  lengths[1] = 1;
  for (size_t i = 2; i < max; i++) {
    lengths[i] = calcLength(i);
  }
  return std::distance(
      lengths.begin(),
      std::max_element(lengths.begin(), lengths.end()));
}
