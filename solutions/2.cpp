#include <utility>

int p2() {
  int result = 0;
  int a = 1;
  int b = 2;
  while (b < 4'000'000) {
    if (b % 2 == 0) {
      result += b;
    }
    a += b;
    std::swap(a, b);
  }
  return result;
}
