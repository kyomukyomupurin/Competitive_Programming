/**
 *  prime factorization
**/

#include <iostream>
#include <vector>

std::vector<std::pair<int64, int64>> prime_fact(int64 n){
  std::vector<std::pair<int64, int64>> result;
  for (int64 i = 2; i * i <= n; ++i){
    if (n % i != 0) continue;
    int cnt = 0;
    while (n % i == 0){
      n /= i; ++cnt;
    }
    result.emplace_back(i, cnt);
  }
  if (n != 1) result.emplace_back(n, 1);
  return result;
}