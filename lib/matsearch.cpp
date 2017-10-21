#include "matsearch.h"

namespace matsearch {

std::istream& operator>>(std::istream& in, Matrix& m) {
  int i;
  while (in >> i) {
    m.emplace_back(i);
    in.get();  // skip ',' or newline
  }
  return in;
}

}
