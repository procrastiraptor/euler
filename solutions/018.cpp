#include <iostream>
#include <iterator>
#include <optional>
#include <vector>

namespace {

struct Node {
  int value;
  Node *left, *right;

  explicit Node(int i) : value(i), left(nullptr), right(nullptr), maxPath_() {}

  int maxPath() const {
    if (maxPath_.has_value()) {
      return maxPath_.value();
    }
    int x = std::max(left ? left->maxPath() : 0, right ? right->maxPath() : 0);
    maxPath_ = value + x;
    return maxPath_.value();
  }

 private:
  mutable std::optional<int> maxPath_;
};

using Tree = std::vector<Node>;

void setupPointers(Tree& t) {
  auto a = t.begin();
  auto b = a + 1;
  for (size_t n = 2; b < t.end(); a = b + n, std::swap(a, b), n++) {
    for (size_t i = 0; i < n - 1; i++) {
      a[i].left = &b[i];
      a[i].right = &b[i + 1];
    }
  }
}

}

int p18() {
  Tree t(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
  if (t.empty()) {
    return 0;
  }
  setupPointers(t);
  return t.front().maxPath();
}
