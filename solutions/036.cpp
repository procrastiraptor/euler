#include <algorithm>
#include <iostream>
#include <string>

#include "lib/palindrome.h"

namespace {

std::string binary(int n) {
  std::string result;
  for (int i = n; i > 0; i >>= 1) {
    result += (i & 0x1 ? "1" : "0");
  }
  return result;
}

}

long p36() {
  long result = 0;
  for (int i = 1; i < 1'000'000; i++) {
    result += (palindrome(std::to_string(i)) && palindrome(binary(i))) ? i : 0;
  }
  return result;
}
