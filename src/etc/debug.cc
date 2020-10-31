// Helper functions and macros for debug output

#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>

// snippet-begin
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class Tuple, std::size_t... Is>
void tuple_out(std::ostream& os, const Tuple& tp, std::index_sequence<Is...>) {
  ((os << (Is ? ", " : "(") << std::get<Is>(tp)), ...) << ")";
}

template <class... Args>
std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& tp) {
  tuple_out(os, tp, std::index_sequence_for<Args...>{});
  return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class Compare>
std::ostream& operator<<(std::ostream& os, const std::set<T, Compare>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U, class Compare>
std::ostream& operator<<(std::ostream& os, const std::map<T, U, Compare>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

#ifdef LOCAL
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
// snippet-end
