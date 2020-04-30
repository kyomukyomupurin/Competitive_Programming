// Miller-Rabin primality test(for 64bit integers)
// verified by
//     https://www.spoj.com/problems/PON/
// reference:
//     https://cp-algorithms.com/algebra/primality_tests.html

#include <iostream>

class MillerRabinTest {
  using uint64 = uint64_t;
  using uint128 = __uint128_t;

 public:
  MillerRabinTest() {}
  uint64 power(uint64 base, uint64 e, uint64 mod) {
    uint64 res = 1;
    base %= mod;
    while (e) {
      if (e & 1) res = (uint128)res * base % mod;
      base = (uint128)base * base % mod;
      e >>= 1;
    }
    return res;
  }

  bool check(uint64 n, uint64 a, uint64 d, int s) {
    uint64 x = power(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
      x = (uint128)x * x % n;
      if (x == n - 1) return false;
    }
    return true;
  };

  bool isprime(uint64 n) {
    if (n < 2) return false;
    int r = 0;
    uint64 d = n - 1;
    while ((d & 1) == 0) {
      d >>= 1;
      r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
      if (n == (uint64)a) return true;
      if (check(n, a, d, r)) return false;
    }
    return true;
  }
};