/**
 *  nCr (mod 1000000007)
**/

#include <iostream>
using int64 = long long;

const int MAX = 2e5;
const int MOD = 1e9 + 7;
int64 fac[MAX] = {}, inv[MAX] = {}, finv[MAX] = {};

void make_table() {
  fac[0] = 1; fac[1] = 1;
  finv[0] = 1; finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

int64 com(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// compile time calculation version
// warning : it takes much more compile time !!
class Combination {
 public:
  constexpr Combination() { Build(); }
  static constexpr int mod_ = 1000000007;
  static constexpr int n_ = 1000000;
  struct LookupTable {
    int64 factorial_[n_];
    int64 inverse_[n_];
    int64 finverse_[n_];
  };
  LookupTable lt{};
  // return nCk
  constexpr int64 Get(int n, int k) const noexcept {
    if (n < k || n < 0 || k < 0) return 0;
    return lt.factorial_[n] * (lt.finverse_[k] * lt.finverse_[n - k] % mod_) %
           mod_;
  }

 private:
  constexpr void Build() noexcept {
    lt.factorial_[0] = 1;
    lt.factorial_[1] = 1;
    lt.finverse_[0] = 1;
    lt.finverse_[1] = 1;
    lt.inverse_[1] = 1;
    for (int i = 2; i < n_; ++i) {
      lt.factorial_[i] = lt.factorial_[i - 1] * i % mod_;
      lt.inverse_[i] = mod_ - lt.inverse_[MOD % i] * (MOD / i) % mod_;
      lt.finverse_[i] = lt.finverse_[i - 1] * lt.inverse_[i] % mod_;
    }
  }
};

Combination kyomukyomupurin;