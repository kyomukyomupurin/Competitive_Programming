/**
 *      purpose : 
 *      author  : kyomukyomupurin
 *      created : 
**/

// input/output
#include <fstream>
#include <iostream>
#include <sstream>
// container class
#include <array>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// math, algorithm
#include <algorithm>
#include <cmath>
#include <complex>
#include <numeric>
// etc
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstring>
#include <chrono>
#include <ext/random>
#include <ext/rope>
#include <functional>
#include <iomanip>
#include <random>
#include <utility>
// using-directive
using namespace std;
// alias template
using int64 = long long;
using uint64 = unsigned long long;
using vi = std::vector<int>;
using vl = std::vector<int64>;
using pii = std::pair<int, int>;
using pii = std::pair<int, int>;
using pll = std::pair<int64, int64>;
// text macro replacement
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(_) (_).begin(), (_).end()
#define rall(_) (_).rbegin(), (_).rend()
#define print(_) std::cout << (_) << '\n'
#define debug(_) std::cerr << #_ << ": " << (_) << '\n'
// variadic template
template<typename T> inline void chmin(T &a, T b) {if (a > b) a = b; return;}
template<typename T> inline void chmax(T &a, T b) {if (a < b) a = b; return;}
template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  os << "{";
  for (size_t i = 0; i < vec.size(); ++i) {
    os << vec[i] << ",}"[i == vec.size() - 1];
  }
  return os;
}
template<typename T, typename U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << "{" << p.first << " " << p.second << "}";
}
// constant
const int INF = (1<<30) - 1;  // 1.073741823e9
const int64 INF64 = (1LL<<62) - 1;  // 4.611686018427387903e18
const int MOD = 1000000007;

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);


  return 0;
}