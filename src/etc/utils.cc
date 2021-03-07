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
inline std::vector<int> compressed(const std::vector<T>& vec) {
  std::vector<T> t = vec;
  std::sort(t.begin(), t.end());
  int n = vec.size();
  t.erase(std::unique(t.begin(), t.end()), t.end());
  std::vector<int> compressed(n);
  for (int i = 0; i < n; ++i)
    compressed[i] =
        std::distance(t.begin(), std::lower_bound(t.begin(), t.end(), vec[i]));
  return compressed;
}

template <class T>
inline std::string to_binary(T n) {
  std::string bin_str = "";
  while (n) bin_str += (n & 1) ? '1' : '0', n >>= 1;
  std::reverse(bin_str.begin(), bin_str.end());
  return bin_str;
}

template <class T>
inline void println(T val) {
  std::cout << val << '\n';
}

inline void println(double val) noexcept {
  std::cout << std::fixed << std::setprecision(17) << val << '\n';
}

inline void println(long double val) noexcept {
  std::cout << std::fixed << std::setprecision(17) << val << '\n';
}

inline void Yes(bool cond) noexcept { println(cond ? "Yes" : "No"); }

inline void YES(bool cond) noexcept { println(cond ? "YES" : "NO"); }

template <class T>
inline bool umax(T& lhs, const T rhs) {
  if (lhs < rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

template <class T>
inline bool umin(T& lhs, const T rhs) {
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
