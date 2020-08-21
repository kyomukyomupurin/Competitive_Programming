// Factor
// verified by
//     https://judge.yosupo.jp/problem/factorize

#include <algorithm>
#include <vector>

using int64 = long long;

// snippet-begin
using int128 = __int128_t;

inline int128 power(int128 base, int128 e, int128 mod) {
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
        ok = true;
        break;
      }
    }
    if (!ok) return false;
  }
  return true;
}

inline int64 fast_gcd(int64 x, int64 y) {
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

template <class T>
inline std::vector<T> connect(const std::vector<T> &a,
                              const std::vector<T> &b) {
  std::vector<T> c(a.size() + b.size());
  std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
  return c;
}

template <class T>
std::vector<T> factor(T n) {
  if (n <= 1) return {};
  if (is_prime(n)) return {n};
  if (~n & 1) return connect({2}, factor(n >> 1));
  for (T c = 1;; ++c) {
    T x = 2, y = 2, d;
    do {
      x = ((int128)x * x + c) % n;
      y = ((int128)y * y + c) % n;
      y = ((int128)y * y + c) % n;
      d = fast_gcd(x - y, n);
    } while (d == 1);
    if (d < n) return connect(factor(d), factor(n / d));
  }
}
// snippet-end

// verification code
/*
void factorize() {
  int t; cin >> t;
  while (t--) {
    int64 n; cin >> n;
    auto v = factor(n);
    cout << v.size();
    for (int64 e : v) {
      cout << " " << e;
    }
    cout << '\n';
  }
}
*/