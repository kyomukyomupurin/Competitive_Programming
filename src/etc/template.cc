/**
 *      purpose : 
 *      author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *      created : 
**/

#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
#define debug(_) cerr << #_ << ": " << (_) << '\n'
template<typename T> inline void chmin(T &a, T b) { if (a > b) a = b; return; }
template<typename T> inline void chmax(T &a, T b) { if (a < b) a = b; return; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& vec) {
  os << '{'; for (size_t i = 0; i < vec.size(); ++i) { os << vec[i]; if (i != vec.size() - 1) os << ','; } os << '}';
  return os;
}
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
  return os << '{' << p.first << " " << p.second << '}';
}
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int64 INF64 = numeric_limits<int64>::max() / 2;
constexpr int MOD = 1000000007;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}