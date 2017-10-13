#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <vector>

using Row = std::vector<int>;
using Grid = std::vector<Row>;

namespace {

auto row(const std::string& s) {
  std::istringstream in(s);
  Row result;
  std::copy(
      std::istream_iterator<int>(in),
      std::istream_iterator<int>(),
      std::back_inserter(result));
  return result;
}

Grid transpose(const Grid& g) {
  Grid result(g.size(), Row(g.size()));
  for (size_t i = 0; i < g.size(); i++) {
    for (size_t j = 0; j < g.size(); j++) {
      result[i][j] = g[j][i];
    }
  }
  return result;
}

Grid diagonals(const Grid& g) {
  Grid result;
  for (size_t len = 1; len <= g.size(); len++) {
    result.emplace_back(len);
    auto& r = result.back();
    for (size_t i = 0; i < len; i++) {
      r[i] = g[i][g.size() - len + i];
    }
    result.emplace_back(len);
    auto& s = result.back();
    for (size_t i = 0; i < len; i++) {
      s[i] = g[g.size() - len + i][i];
    }
  }
  return result;
}

Grid rotate(const Grid& g) {
  Grid result(g.size(), Row(g.size()));
  for (size_t i = 0; i < g.size(); i++) {
    for (size_t j = 0; j < g.size(); j++) {
      result[i][j] = g[g.size() - 1 - j][i];
    }
  }
  return result;
}

template<class It>
int product(It begin, It end) {
  return std::accumulate(begin, end, 1, std::multiplies<int>{});
}

int topProduct(const Row& r) {
  constexpr size_t productSize = 4;

  if (r.size() < productSize) {
    return 0;
  } else if (r.size() == productSize) {
    return product(r.begin(), r.end());
  }
  std::vector<int> ps(r.size() - productSize);
  std::transform(
      r.begin(),
      r.end() - productSize,
      ps.begin(),
      [](const int& i) { return product(&i, &i + productSize); });
  return *std::max_element(ps.begin(), ps.end());
}

}

int p11() {
  Grid rows;
  std::string line;
  while (std::getline(std::cin, line, '\n')) {
    rows.emplace_back(row(line));
  }
  if (rows.empty()) {
    return 0;
  }

  Grid all(rows);
  all.reserve(all.size() * 6);
  auto cols = transpose(rows);
  std::move(cols.begin(), cols.end(), std::back_inserter(all));
  auto diag = diagonals(rows);
  std::move(diag.begin(), diag.end(), std::back_inserter(all));
  diag = diagonals(rotate(rows));
  std::move(diag.begin(), diag.end(), std::back_inserter(all));


  std::vector<int> ps;
  ps.reserve(all.size());
  std::transform(all.begin(), all.end(), std::back_inserter(ps), topProduct);
  return *std::max_element(ps.begin(), ps.end());
}
