// Helper functions

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
// #include <string>
#include <tuple>
#include <vector>

// snippet-begin
inline void Yes(bool cond) noexcept { std::cout << (cond ? "Yes" : "No") << '\n'; }

inline void YES(bool cond) noexcept { std::cout << (cond ? "YES" : "NO") << '\n'; }

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

template <class T, class U>
std::istream& operator>>(std::istream& is, std::pair<T, U>& p) {
  return is >> p.first >> p.second;
}

template <class Tuple, std::size_t... Is>
void tuple_in(std::istream& is, Tuple& tup, std::index_sequence<Is...>) {
  ((is >> std::get<Is>(tup)), ...);
}

template <class... Args>
std::istream& operator>>(std::istream& is, std::tuple<Args...>& tup) {
  tuple_in(is, tup, std::index_sequence_for<Args...>{});
  return is;
}
// snippet-end
