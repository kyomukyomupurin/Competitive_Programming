// fast gcd
// verified by
//     https://atcoder.jp/contests/abc162/tasks/abc162_c
// reference:
//     https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/

#include <algorithm>

// snippet-begin
unsigned long long fast_gcd(unsigned long long x, unsigned long long y) {
  int shift;
  if (x == 0) return y;
  if (y == 0) return x;
  shift = __builtin_ctzll(x | y);
  x >>= __builtin_ctzll(x);
  do {
    y >>= __builtin_ctzll(y);
    if (x > y) std::swap(x, y);
    y -= x;
  } while (y);
  return x << shift;
}
// snippet-end
