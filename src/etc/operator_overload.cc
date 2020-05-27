// operator overloading

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <vector>

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class Ch, class Tr, class Tuple, std::size_t... Is>
void tuple_out(std::basic_ostream<Ch, Tr>& os, const Tuple& tp, std::index_sequence<Is...>) {
  ((os << (Is ? ", " : "(") << std::get<Is>(tp)), ...) << ")";
}

template <class Ch, class Tr, class... Args>
auto& operator<<(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& tp) {
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

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
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

int main() {
  std::vector<int> v1;
  v1.emplace_back(0);
  v1.emplace_back(1);
  v1.emplace_back(2);

  debug(v1);  // [v1]: {0, 1, 2}

  std::set<int> st1;
  st1.emplace(0);
  st1.emplace(1);
  st1.emplace(2);
  std::set<int, std::greater<int>> st2;
  st2.emplace(0);
  st2.emplace(1);
  st2.emplace(2);

  debug(st1, st2);  // [st1, st2]: {0, 1, 2}, {2, 1, 0}

  std::map<int, int> mp1;
  mp1.emplace(0, 1);
  mp1.emplace(1, 2);
  mp1.emplace(2, 3);
  std::map<int, int, std::greater<int>> mp2;
  mp2.emplace(0, 1);
  mp2.emplace(1, 2);
  mp2.emplace(2, 3);

  debug(mp1, mp2);  // [mp1, mp2]: {(0, 1), (1, 2), (2, 3)}, {(2, 3), (1, 2), (0, 1)}

  std::pair<int, int> p = {0, 1};
  std::tuple<int, char, std::string> tp = {0, 'a', "Hello"};

  debug(p, tp);  // [p, tp]: (0, 1), (0, a, Hello)

  std::vector<int> ev;
  std::set<int> est;
  std::map<int, int> emp;

  debug(ev, est, emp);  // [ev, est, emp]: {}, {}, {}

  std::vector<std::tuple<int, int, int>> v2;
  v2.emplace_back(0, 1, 2);
  v2.emplace_back(1, 2, 3);
  v2.emplace_back(2, 3, 4);

  debug(v2);  // [v2]: {(0, 1, 2), (1, 2, 3), (2, 3, 4)}

  int n;
  std::cin >> n;  // 5
  std::vector<int> v3(n);
  std::cin >> v3;  // 1 2 3 4 5

  debug(v3);  // [v3]: {1, 2, 3, 4, 5}

  return 0;
}