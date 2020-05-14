// operator overloading

#include <iostream>
#include <map>
#include <set>
#include <vector>

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
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
  std::vector<int> v = {1, 2, 3};
  std::map<int, int> mp = {{4, 5}, {6, 7}};
  std::set<int> st = {8, 9, 10};
  std::map<std::pair<int, int>, int> mp2 = {{{11, 12}, 13}, {{14, 15}, 16}};
  std::vector<int> v2;
  std::set<int> st2;
  std::map<int, int> mp3;

  debug(v, mp, st, mp2);  // output : [v, mp, st, mp2]: {1, 2, 3}, {(4, 5), (6, 7)}, {8, 9, 10}, {((11, 12), 13), ((14, 15), 16)}
  debug(v2, st2, mp3);    // output : [v2, st2, mp3]: {}, {}, {}

  int n;
  std::cin >> n;  // input : 5
  std::vector<int> v3(n);
  std::cin >> v3;  // input : 2 4 6 8 10

  debug(v3);  // output : [v3] : {2, 4, 6, 8, 10}

  return 0;
}