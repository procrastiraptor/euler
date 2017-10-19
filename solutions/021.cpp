#include <algorithm>
#include <numeric>
#include <vector>

namespace {

int sumOfDivisors(int n) {
  int result = 0;
  for (int i = 1; i <= n / 2; i++) {
    result += (n % i == 0 ? i : 0);
  }
  return result;
}

bool amicable(const std::vector<int>& v, int i) {
  if (i < 1 || static_cast<size_t>(i) > v.size()) {
    return false;
  }
  auto sum = v[i - 1];
  if (sum == i || sum < 1) {
    return false;
  }
  if (static_cast<size_t>(sum) > v.size()) {
    return sumOfDivisors(sum) == i;
  }
  return v[sum - 1] == i;
}

}

int p21() {
  constexpr int max = 10'000;
  std::vector<int> ds(max);
  std::iota(ds.begin(), ds.end(), 1);
  std::transform(ds.begin(), ds.end(), ds.begin(), sumOfDivisors);
  int result = 0;
  for (int i = 1; i < max; i++) {
    result += (amicable(ds, i) ? i : 0);
  }
  return result;
}
