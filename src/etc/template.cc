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
using ull = unsigned long long;
// text macro replacement
#define debug(_) std::cerr << #_ << ": " << (_) << '\n'
// variadic template
template<typename T> inline void chmin(T &a, T b) {if (a > b) a = b; return;}
template<typename T> inline void chmax(T &a, T b) {if (a < b) a = b; return;}
template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  os << '{';
  for (size_t i = 0; i < vec.size(); ++i) {
    os << vec[i];
    if (i != vec.size() - 1) os << ',';
  }
  os << '}';
  return os;
}
template<typename T, typename U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '{' << p.first << " " << p.second << '}';
}
// constant
constexpr int INF = std::numeric_limits<int>::max() / 2;  // 1.073741823e9
constexpr int64 INF64 = std::numeric_limits<int64>::max() / 2;  // 4.611686018427387903e18
constexpr int MOD = 1000000007;

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);


  return 0;
}