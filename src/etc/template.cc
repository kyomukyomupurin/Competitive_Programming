/**
 *    author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *    created : 
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

template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) { os << '{'; size_t n = vec.size(); for (size_t i = 0; i < n; ++i) { os << vec[i]; if (i != n - 1) os << ','; } os << '}'; return os; }
template<class T, class U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) { return os << '{' << p.first << " " << p.second << '}'; }
template<class T, class U> std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) { for (auto it = mp.begin(); it != mp.end(); ++it) { os << '{' << it->first << ':' << it->second << '}'; if (it != --mp.end()) os << ','; } return os; }
template<class T> std::ostream& operator<<(std::ostream& os, const std::set<T>& st) { os << '{'; for (auto it = st.begin(); it != st.end(); ++it) { os << *it; if (it != --st.end()) os << ','; } os << '}'; return os; }
template<class T> std::istream& operator>>(std::istream& is, std::vector<T>& vec) { size_t n = vec.size(); for (size_t i = 0; i < n; ++i) is >> vec[i]; return is; }

#define all(_) begin(_), end(_)
#define rall(_) rbegin(_), rend(_)

#ifdef LOCAL
#define debug(_) cerr << #_ << ": " << (_) << '\n'
#else
#define debug(_) 1728
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);


  return 0;
}