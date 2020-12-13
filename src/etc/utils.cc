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
inline int lower_position(const std::vector<T>& vec, T val) {
  return std::distance(vec.begin(),
                       std::lower_bound(vec.begin(), vec.end(), val));
}

template <class T>
inline int upper_position(const std::vector<T>& vec, T val) {
  return std::distance(vec.begin(),
                       std::upper_bound(vec.begin(), vec.end(), val));
}

template <class T>
inline std::vector<int> compressed(const std::vector<T>& vec) {
  std::vector<T> t = vec;
  std::sort(t.begin(), t.end());
  int n = vec.size();
  int w = 0;
  for (int i = 0; i < n; ++i) {
    if (!(w > 0 && t[w - 1] == t[i])) {
      std::swap(t[w], t[i]);
      ++w;
    }
  }
  t.resize(w);
  std::vector<int> compressed(n);
  for (int i = 0; i < n; ++i)
    compressed[i] =
        std::distance(t.begin(), std::lower_bound(t.begin(), t.end(), vec[i]));
  return compressed;
}

template <class T>
inline std::string to_binary(T n) {
  assert(n > 0);
  std::string ret = "";
  while (n) ret += (n & 1) ? '1' : '0', n >>= 1;
  std::reverse(ret.begin(), ret.end());
  return ret;
}

template <class T>
inline void println(T val) {
  std::cout << val << '\n';
}

inline void println(double val) {
  std::cout << std::fixed << std::setprecision(17) << val << '\n';
}

inline void println(long double val) {
  std::cout << std::fixed << std::setprecision(17) << val << '\n';
}

template <class T>
inline void println(const std::vector<T>& vec, const char del = ' ') {
  bool first = true;
  for (T e : vec) {
    if (!first) std::cout << del;
    first = false;
    std::cout << e;
  } 
  std::cout << '\n';
}

inline void Yes(bool cond) {
  println(cond ? "Yes" : "No");
}

inline void YES(bool cond) {
  println(cond ? "YES" : "NO");
}

template <class T>
using binary_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

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
void tuple_in(std::istream& is, Tuple& tp, std::index_sequence<Is...>) {
  ((is >> std::get<Is>(tp)), ...);
}

template <class... Args>
std::istream& operator>>(std::istream& is, std::tuple<Args...>& tp) {
  tuple_in(is, tp, std::index_sequence_for<Args...>{});
  return is;
}
// snippet-end
