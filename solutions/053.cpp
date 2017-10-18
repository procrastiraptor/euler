#include "lib/choose.h"

int p53() {
  int result = 0;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= i; j++) {
      auto c = choose(i, j);
      if (c > 1'000'000) {
        result++;
      }
    }
  }
  return result;
}
