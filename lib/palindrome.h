#pragma once

template<class C>
bool palindrome(const C& c) {
  return std::equal(c.begin(), c.end(), c.rbegin());
}
