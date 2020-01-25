// Prime Factorization

#include <iostream>
#include <vector>
#include <map>

using int64 = long long;

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

std::map<int64, int> prime_fact_(int64 n){
  std::map<int64, int> result;
  for (int64 i = 2; i * i <= n; ++i){
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