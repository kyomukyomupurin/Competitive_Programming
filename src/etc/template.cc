/**
 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *    created : $CURRENT_YEAR-$CURRENT_MONTH-$CURRENT_DATE $CURRENT_HOUR:$CURRENT_MINUTE:$CURRENT_SECOND
**/

#include <iostream>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <numeric>
#include <bitset>
#include <cassert>
#include <cctype>
#include <iomanip>
#include <random>
#include <utility>
#include <chrono>

using namespace std;

using int64 = long long;

template <class T> using binary_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T, class U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) { int flag = 0; for (auto e : vec) os << (flag++ ? ", " : "{") << e; return os << '}'; }
template <class T> std::ostream& operator<<(std::ostream& os, const std::set<T>& st) { int flag = 0; for (auto e : st) os << (flag++ ? ", " : "{") << e; return os << '}'; }
template <class T, class U> std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) { int flag = 0; for (auto e : mp) os << (flag++ ? ", " : "{") << e; return os << '}'; }
template <class T> std::istream& operator>>(std::istream& is, std::vector<T>& vec) { for (T& e : vec) is >> e; return is; }

#define all(_) begin(_), end(_)
#define rall(_) rbegin(_), rend(_)

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}