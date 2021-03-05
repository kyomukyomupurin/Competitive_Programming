// Rolling Hash
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B
//     https://atcoder.jp/contests/abc141/tasks/abc141_e

#include <chrono>
#include <string>
#include <tuple>
#include <vector>

using int64 = long long;

// snippet-begin
class RollingHash {
  using Hashes = std::tuple<int64, int64, int64>;

 public:
  RollingHash(const std::string& str) {
    int n = str.size();
    h0_.reserve(n + 1);
    h1_.reserve(n + 1);
    h2_.reserve(n + 1);
    h0_.emplace_back(1);
    h1_.emplace_back(1);
    h2_.emplace_back(1);
    for (int i = 0; i < n; ++i) {
      h0_.emplace_back((h0_.back() * base0_ + str[i]) % mod0_);
      h1_.emplace_back((h1_.back() * base1_ + str[i]) % mod1_);
      h2_.emplace_back((h2_.back() * base2_ + str[i]) % mod2_);
    }
    while (int(pow0_.size()) < n + 1) {
      pow0_.emplace_back(pow0_.back() * base0_ % mod0_);
      pow1_.emplace_back(pow1_.back() * base1_ % mod1_);
      pow2_.emplace_back(pow2_.back() * base2_ % mod2_);
    }
  }

  // get hash value of str[l, r)
  Hashes get(int l, int r) const {
    int64 hash0 = (h0_[r] - h0_[l] * pow0_[r - l]) % mod0_;
    int64 hash1 = (h1_[r] - h1_[l] * pow1_[r - l]) % mod1_;
    int64 hash2 = (h2_[r] - h2_[l] * pow2_[r - l]) % mod2_;
    if (hash0 < 0) hash0 += mod0_;
    if (hash1 < 0) hash1 += mod1_;
    if (hash2 < 0) hash2 += mod2_;
    return {hash0, hash1, hash2};
  }

 private:
  static constexpr int64 mod0_ = 2000000011; // prime number
  static constexpr int64 mod1_ = 2000000033; // prime number
  static constexpr int64 mod2_ = 2000000099; // prime number
  static constexpr int64 base0_ = 100001; // primitive root of 2000000011
  static constexpr int64 base1_ = 100000; // primitive root of 2000000033
  static constexpr int64 base2_ = 100002; // primitive root of 2000000099
  std::vector<int64> h0_;
  std::vector<int64> h1_;
  std::vector<int64> h2_;
  static std::vector<int64> pow0_;
  static std::vector<int64> pow1_;
  static std::vector<int64> pow2_;
};

std::vector<int64> RollingHash::pow0_{1};
std::vector<int64> RollingHash::pow1_{1};
std::vector<int64> RollingHash::pow2_{1};
// snippet-end

// verification code
/*
void ABC141_E() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  RollingHash rh(s);

  auto ok = [&](int x) -> bool {
    for (int i = 0; i + 2 * x <= n; ++i) {
      for (int j = i + x; j + x <= n; ++j) {
        if (rh.get(i, i + x) == rh.get(j, j + x)) {
          return true;
        }
      }
    }
    return false;
  };

  int low = 0, high = n / 2 + 1;

  while (high - low > 1) {
    int mid = (low + high) >> 1;
    if (ok(mid)) {
      low = mid;
    } else {
      high = mid;
    }
  }

  cout << low << '\n';
}
*/
/*
void ALDS1_14_B() {
  string t, p;
  cin >> t >> p;
  RollingHash rh0(t);
  RollingHash rh1(p);

  int n = t.size();
  int m = p.size();

  for (int i = 0; i + m <= n; ++i) {
    if (rh0.get(i, i + m) == rh1.get(0, m)) {
      cout << i << '\n';
    }
  }
}
*/