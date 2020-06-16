// Divisor Enumeration

#include <algorithm>
#include <vector>

// snippet-begin
template<class _Tp> std::vector<_Tp> divisor(_Tp n) {
  std::vector<_Tp> res;
  for (_Tp i = 1; i * i <= n; ++i) {
    if (n % i == 0){
      res.emplace_back(i);
      if (i * i != n){
        res.emplace_back(n / i);
      }
    }
  }
  std::sort(res.begin(), res.end());

  return res;
}
// snippet-end
