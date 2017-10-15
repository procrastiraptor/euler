#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <mutex>
#include <optional>
#include <vector>

namespace {

struct Node {
  int value;
  Node *left, *right;

  explicit Node(int i)
    : value(i),
      left(nullptr),
      right(nullptr),
      m_(std::make_unique<std::mutex>()),
      maxPath_() {}

  int maxPath() const {
    std::lock_guard<std::mutex> g(*m_);
    if (maxPath_.has_value()) {
      return maxPath_.value();
    }
    int x = std::max(left ? left->maxPath() : 0, right ? right->maxPath() : 0);
    maxPath_ = value + x;
    return maxPath_.value();
  }

 private:
  std::unique_ptr<std::mutex> m_;
  mutable std::optional<int> maxPath_;
};

using Tree = std::vector<Node>;

void setupPointers(Tree& t) {
  Node* a = t.data();
  Node* b = a + 1;
  for (size_t n = 2; b < t.data() + t.size(); a = b + n, std::swap(a, b), n++) {
    for (size_t i = 0; i < n - 1; i++) {
      a[i].left = &b[i];
      a[i].right = &b[i + 1];
    }
  }
}

}

int p18() {
  Tree t;
  std::transform(
      std::istream_iterator<int>(std::cin),
      std::istream_iterator<int>(),
      std::back_inserter(t),
      [](int v) { return Node{v}; });
  if (t.empty()) {
    return 0;
  }
  setupPointers(t);
  return t.front().maxPath();
}
