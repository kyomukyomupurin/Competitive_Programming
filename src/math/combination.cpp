/**
 *  nCr (mod 1000000007)
**/

#include <iostream>
using namespace std;

const int MAX = 2e5;
const int MOD = 1e9 + 7;
int64_t fac[MAX] = {}, inv[MAX] = {}, finv[MAX] = {};

void make_table(){
  fac[0] = 1; fac[1] = 1;
  finv[0] = 1; finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

int64_t com(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}