// operator overloading

#include <iostream>
#include <map>
#include <set>
#include <vector>

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  os << '{';
  bool first = 0;
  for (T e : vec) {
    if (first) os << ", ";
    os << e;
    first = 1;
  }
  os << '}';
  return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  os << '{';
  bool first = 0;
  for (T e : st) {
    if (first) os << ", ";
    os << e;
    first = 1;
  }
  os << '}';
  return os;
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  os << '{';
  bool first = 0;
  for (auto [key, value] : mp) {
    if (first) os << ", ";
    os << '(' << key << ", " << value << ')';
    first = 1;
  }
  os << '}';
  return os;
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
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

  debug(v, mp, st, mp2);  // output : [v, mp, st, mp2]: {1, 2, 3}, {(4, 5), (6, 7)}, {8, 9, 10}, {((11, 12), 13), ((14, 15), 16)}

  int n;
  std::cin >> n;  // input : 5
  std::vector<int> v2(n);
  std::cin >> v2;  // input : 2 4 6 8 10

  debug(v2);  // output : [v2] : {2, 4, 6, 8, 10}

  return 0;
}