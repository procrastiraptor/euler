#include <gmpxx.h>
#include <iostream>
#include <string>

long p13() {
  mpz_class total;
  std::string line;
  while (std::getline(std::cin, line, '\n')) {
    total += mpz_class{line};
  }
  auto s = total.get_str().substr(0, 10);
  return std::stol(s);
}
