// fast gcd
// verified by
//     https://atcoder.jp/contests/abc162/tasks/abc162_c
// reference:
//     https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/

#include <algorithm>

using int64 = long long;

// snippet-begin
int64 fast_gcd(int64 x, int64 y) {
  if (x < 0) x = -x;
  if (y < 0) y = -y;
  if (!x) return y;
  if (!y) return x;
  int s = __builtin_ctzll(x | y);
  x >>= __builtin_ctzll(x);
  do {
    y >>= __builtin_ctzll(y);
    if (x > y) std::swap(x, y);
    y -= x;
  } while (y);
  return x << s;
}
// snippet-end
