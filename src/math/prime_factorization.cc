// Prime Factorization

#include <iostream>
#include <map>

using int64 = long long;
// snippet-begin
template<class _Tp>
std::map<_Tp, int> prime_fact(_Tp n){
  std::map<_Tp, int> result;
  for (_Tp i = 2; i * i <= n; ++i){
    if (n % i != 0) continue;
    int cnt = 0;
    while (n % i == 0){
      n /= i; ++cnt;
    }
    result[i] = cnt;
  }
  if (n != 1) result[n] = 1;
  return result;
}
// snippet-end
