// binary gcd
// verified by
//     https://atcoder.jp/contests/abc162/tasks/abc162_c
// reference:
//     https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/

#include <algorithm>

using int64 = long long;

// snippet-begin
template <class T>
T binary_gcd(T x, T y) {
  assert(x >= 0 && y >= 0);
  unsigned long long tx = x, ty = y;
  if (!tx || !ty) return tx ^ ty ^ 0;
  int s = __builtin_ctzll(tx | ty);
  tx >>= __builtin_ctzll(tx);
  do {
    ty >>= __builtin_ctzll(ty);
    if (tx > ty) std::swap(tx, ty);
    ty -= tx;
  } while (ty);
  return static_cast<T>(tx << s);
}
// snippet-end
