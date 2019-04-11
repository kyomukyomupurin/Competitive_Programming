/**
 *  prime factorization
**/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int64_t, int64_t>> prime_fact(int64_t n){
  vector<pair<int64_t, int64_t>> result;
  for (int64_t i = 2; i * i <= n; ++i){
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