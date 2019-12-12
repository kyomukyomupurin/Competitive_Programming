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
#include <functional>
#include <iomanip>
#include <random>
#include <utility>

using namespace std;

using int64 = long long;
template<class T> ostream& operator<<(ostream& os, vector<T>& _) { os << '{'; for (T& x : _) { os << x; if (&x != &_.back()) os << ','; } os << '}'; return os; }
template<class T, class U> ostream& operator<<(ostream& os, pair<T, U>& p) { return os << '{' << p.first << " " << p.second << '}'; }

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