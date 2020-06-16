// nCr (mod 1000000007)
// verified by
//     https://atcoder.jp/contests/abc154/tasks/abc154_f

#include <iostream>
#include <array>

using int64 = long long;

// snippet-begin
class Combination {
 public:
  static constexpr int mod_ = 1000000007;
  static constexpr int n_ = 2000000 + 5;

  Combination() { build(); }

  std::array<int64, n_> fact_;
  std::array<int64, n_> inv_;
  std::array<int64, n_> finv_;

  // return nCk
  int64 get(int n, int k) const noexcept {
    if (n < k || n < 0 || k < 0) return 0;
    return fact_[n] * (finv_[k] * finv_[n - k] % mod_) % mod_;
  }

 private:
  void build() noexcept {
    fact_[0] = 1;
    fact_[1] = 1;
    finv_[0] = 1;
    finv_[1] = 1;
    inv_[1] = 1;
    for (int i = 2; i < n_; ++i) {
      fact_[i] = fact_[i - 1] * i % mod_;
      inv_[i] = mod_ - inv_[mod_ % i] * (mod_ / i) % mod_;
      finv_[i] = finv_[i - 1] * inv_[i] % mod_;
    }
  }
};
// snippet-end

// verification code
/*
void ABC_154_F() {
  int64 r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  int64 ans = 0;

  Combination kyomu;

  for (int64 i = r1; i <= r2; ++i) {
    ans += (((c2 + 1LL) * kyomu.get(c2 + i + 1LL, i) % kyomu.mod_) * kyomu.inv_[i + 1]) % kyomu.mod_ - ((c1 * kyomu.get(c1 + i, i) % kyomu.mod_) * kyomu.inv_[i + 1] % kyomu.mod_);
    while (ans < 0) ans += kyomu.mod_;
    ans %= kyomu.mod_;
  }

  cout << ans << endl;
}
*/