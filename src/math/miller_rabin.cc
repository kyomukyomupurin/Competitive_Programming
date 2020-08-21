// Miller-Rabin primality test(for 64bit integers)
// verified by
//     https://www.spoj.com/problems/PON/
// reference:
//     https://cp-algorithms.com/algebra/primality_tests.html

#include <iostream>

using int64 = long long;

// snippet-begin
using int128 = __int128_t;

int128 power(int128 base, int128 e, int128 mod) {
  int128 res = 1;
  base %= mod;
  while (e) {
    if (e & 1) res = res * base % mod;
    (base *= base) %= mod;
    e >>= 1;
  }
  return res;
}

bool is_prime(int64 n) {
  if (n < 2 || ~n & 1) return n == 2;
  int s = __builtin_ctzll(n - 1);
  int64 d = (n - 1) >> s;
  for (int64 base : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    int128 x = base % n;
    if (!x) continue;
    x = power(x, d, n);
    if (x == 1 || x == n - 1) continue;
    bool ok = false;
    for (int i = 0; i < s - 1; ++i) {
      (x *= x) %= n;
      if (x == n - 1) {
        ok = true; break;
      }
    }
    if (!ok) return false;
  }
  return true;
}
// snippet-end
