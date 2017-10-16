#include <array>
#include <vector>

namespace {

constexpr std::array<int, 8> cents = { 1, 2, 5, 10, 20, 50, 100, 200, };

int combos(std::vector<int> coins, int total) {
  if (coins.empty()) {
    return 0;
  }
  int c = coins.back();
  int keep = total < c ? 0 : (total == c) + combos(coins, total - c);
  coins.pop_back();
  int drop = combos(std::move(coins), total);
  return keep + drop;
}

}

int p31() {
  return combos(std::vector<int>(cents.begin(), cents.end()), 200);
}
