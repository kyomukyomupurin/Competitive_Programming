// nCr (mod 1000000007)
// compile time calculation version
// warning : it takes much more compile time and sometimes ends up with compilation error !!
// if n_ >= 10^6, remove "constexpr"

#include <iostream>

using int64 = long long;

class Combination {
 public:
  constexpr Combination() { Build(); }
  static constexpr int mod_ = 1000000007;

  #ifdef LOCAL
  static constexpr int n_ = 1000 + 5;
  #else
  static constexpr int n_ = 200000 + 5;
  #endif

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
      lt.inverse_[i] = mod_ - lt.inverse_[mod_ % i] * (mod_ / i) % mod_;
      lt.finverse_[i] = lt.finverse_[i - 1] * lt.inverse_[i] % mod_;
    }
  }
};