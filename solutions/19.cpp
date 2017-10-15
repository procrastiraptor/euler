#include <array>

namespace {

std::array<int, 12> lengths = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

constexpr bool leap(int year) {
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

}

int p19() {
  int result = 0;
  int weekday = 1;
  for (int y = 1900; y <= 2000; y++) {
    for (int m = 0; m < 12; m++) {
      int max = lengths[m];
      max += (m == 1 && leap(y));
      result += (y > 1900 && weekday % 7 == 0);
      weekday += max;
    }
  }
  return result;
}
