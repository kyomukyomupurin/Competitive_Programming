// Prime Factorization

#include <iostream>
#include <map>

using int64 = long long;

// snippet-begin
template<class T>
std::map<T, int> prime_fact(T n){
  std::map<T, int> result;
  for (T i = 2; i * i <= n; ++i){
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
