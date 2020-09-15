// Factor
// verified by
//     https://judge.yosupo.jp/problem/factorize

#include <algorithm>
#include <vector>

#include "./binary_gcd.cc"
#include "./miller_rabin.cc"

using int64 = long long;

// snippet-begin
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
      d = binary_gcd(x - y, n);
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