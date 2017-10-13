#include <iostream>

#include "solutions/map.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "usage: euler <problem>\n";
    return 1;
  }
  int n = std::atoi(argv[1]);
  if (n <= 0) {
    return 1;
  }
  auto it = solutions.find(n);
  if (it == solutions.end()) {
    std::cerr << "problem " << n << " not solved yet\n";
    return 1;
  }
  std::cout << it->second() << '\n';
  return 0;
}
