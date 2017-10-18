#include <algorithm>
#include <string>
#include <vector>

#include "lib/primes.h"

namespace {

using Family = std::vector<long>;

auto wildcards(const std::string& s) {
  std::vector<std::string> result(s.size());
  std::transform(
      s.begin(),
      s.end(),
      result.begin(),
      [&s](char c) {
        std::string r(s);
        std::replace(r.begin(), r.end(), c, '*');
        return r;
      });
  std::sort(result.begin(), result.end());
  auto it = std::unique(result.begin(), result.end());
  result.erase(it, result.end());
  return result;
}

auto family(const std::string& s) {
  size_t sz = 10;
  char c = '0';
  if (s.front() == '*') {
    // No leading zeroes.
    sz--;
    c++;
  }
  Family f(sz);
  std::transform(f.begin(), f.end(), f.begin(), [&s,c](long) mutable {
      std::string d(s);
      std::replace(d.begin(), d.end(), '*', c++);
      return std::stol(d);
    });
  return f;
}

auto families(long p) {
  auto ws = wildcards(std::to_string(p));
  std::vector<Family> result(ws.size());
  std::transform(ws.begin(), ws.end(), result.begin(), family);
  return result;
}

}

int p51() {
  for (auto p : primes::upTo(1'000'000)) {
    auto fs = families(p);
    if (std::any_of(fs.begin(), fs.end(), [](const auto& f) {
            return std::count_if(f.begin(), f.end(), primes::is) == 8;
          })) {
      return p;
    }
  }
  return 0;
}
