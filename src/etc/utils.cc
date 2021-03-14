// Helper functions

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

// snippet-begin
template <class T>
inline void println(T val) {
  std::cout << val << '\n';
}

inline void println() { std::cout << '\n'; }

template <class Head, class... Tail>
inline void println(Head&& head, Tail&&... tail) {
  std::cout << head;
  if (sizeof...(Tail) != 0) std::cout << ' ';
  println(std::forward<Tail>(tail)...);
}

inline void Yes(bool cond) noexcept { println(cond ? "Yes" : "No"); }

inline void YES(bool cond) noexcept { println(cond ? "YES" : "NO"); }

template <class T>
inline bool upmax(T& lhs, const T rhs) {
  if (lhs < rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

template <class T>
inline bool upmin(T& lhs, const T rhs) {
  if (lhs > rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

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
