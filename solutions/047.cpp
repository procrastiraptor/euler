#include <algorithm>
#include <array>
#include <numeric>

#include "lib/primes.h"

int p47() {
  std::array<int, 4> arr{ 1, 2, 3, 4, };
  for(; ; std::iota(arr.begin(), arr.end(), 1 + arr.front())) {
    if (std::all_of(
          arr.begin(),
          arr.end(),
          [](int i) { return primes::factorsOf(i).size() == 4; })) {
      return arr.front();
    }
  }
  return 0;
}
