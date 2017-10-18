#include <algorithm>
#include <array>
#include <functional>
#include <numeric>
#include <optional>
#include <vector>

#include "lib/permutations.h"

namespace {

struct Fraction {
  int n, d;

  Fraction() : n(0), d(1) {}
  explicit Fraction(int a) : n(a), d(1) {}
  Fraction(int a, int b) : n(a), d(b) {}

  std::optional<int> eval() const {
    if (std::gcd(n, d) == d && n / d > 0) {
      return n / d;
    }
    return {};
  }
};

Fraction operator+(Fraction a, Fraction b) {
  return { a.n * b.d + b.n * a.d, a.d * b.d };
}

Fraction operator-(Fraction a, Fraction b) {
  return { a.n * b.d - b.n * a.d, a.d * b.d };
}

Fraction operator*(Fraction a, Fraction b) {
  return { a.n * b.n, a.d * b.d };
}

Fraction operator/(Fraction a, Fraction b) {
  return { a.n * b.d, a.d * b.n };
}

struct Stack {
  auto size() const {
    return sz_;
  }

  auto peek() const {
    return data_.at(sz_ - 1);
  }

  auto pop() {
    return data_.at(--sz_);
  }

  void push(Fraction f) {
    data_[sz_++] = f;
  }

 private:
  std::array<Fraction, 4> data_;
  size_t sz_ = 0;
};

std::optional<std::function<Fraction(Fraction, Fraction)>> oper(char c) {
  switch (c) {
  case '+':
    return std::plus<Fraction>();
  case '-':
    return std::minus<Fraction>();
  case '*':
    return std::multiplies<Fraction>();
  case '/':
    return std::divides<Fraction>();
  }
  return {};
}

std::optional<int> eval(std::string_view expr) {
  Stack s;
  for (char c : expr) {
    if (std::isdigit(c)) {
      s.push(Fraction{c - '0'});
      continue;
    } else if (s.size() < 2) {
      return {};
    }
    auto op = oper(c);
    if (!op.has_value()) {
      return {};
    }
    auto a = s.pop();
    auto b = s.pop();
    s.push(op.value()(a, b));
  }
  if (s.size() == 1) {
    return s.peek().eval();
  }
  return {};
}

auto results(const std::string& expr) {
  auto es = permutations(expr);
  std::vector<std::optional<int>> rs(es.size());
  std::transform(es.begin(), es.end(), rs.begin(), eval);
  auto it = std::remove_if(
      rs.begin(), rs.end(), [](const auto& oi) { return !oi.has_value(); });
  std::vector<int> result;
  std::transform(
      rs.begin(),
      it,
      std::back_inserter(result),
      [](const auto& oi) { return oi.value(); });
  return result;
}

int consecutive(const std::vector<int>& v) {
  auto it = std::find_if_not(
      v.begin(),
      v.end(),
      [i=1](int n) mutable { return n == i++; });
  return std::distance(v.begin(), it);
}

constexpr std::array<char, 4> ops = { '+', '-', '*', '/', };

int check(std::array<int, 4> digits) {
  auto expr = std::accumulate(
      digits.begin(),
      digits.end(),
      std::string{},
      [](auto s, int d) { return s + std::to_string(d); });
  std::vector<int> result;
  expr += "   ";  // space for ops
  for (char x : ops) {
    expr[4] = x;
    for (char y : ops) {
      expr[5] = y;
      for (char z : ops) {
        expr[6] = z;
        auto rs = results(expr);
        std::copy(rs.begin(), rs.end(), std::back_inserter(result));
      }
    }
  }
  std::sort(result.begin(), result.end());
  auto it = std::unique(result.begin(), result.end());
  result.erase(it, result.end());
  return consecutive(result);
}

}

int p93() {
  int max = 0;
  int res = 0;
  for (int a = 1; a <= 9; a++) {
    for (int b = a + 1; b <= 9; b++) {
      for (int c = b + 1; c <= 9; c++) {
        for (int d = c + 1; d <= 9; d++) {
          auto i = check({a, b, c, d, });
          if (i > max) {
            max = i;
            res = a * 1000 + b * 100 + c * 10 + d;
          }
        }
      }
    }
  }
  return res;
}
