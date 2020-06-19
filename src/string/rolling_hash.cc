// Rolling Hash
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B
//     https://atcoder.jp/contests/abc141/tasks/abc141_e

#include <chrono>
#include <string>
#include <vector>
#include <random>

// snippet-begin
using ull = unsigned long long;

class RollingHash {
 public:
  RollingHash(const std::string& str) : str_(str) { build(); }

  // get hash value of [l, r)
  std::pair<ull, ull> get(int l, int r) {
    ull ret0 = (hash0_[r] - hash0_[l] * pow0_[r - l] % mod0_ + mod0_) % mod0_;
    ull ret1 = (hash1_[r] - hash1_[l] * pow1_[r - l] % mod1_ + mod1_) % mod1_;
    return {ret0, ret1};
  }

 private:
  const std::string str_;
  static ull base0_;
  static ull base1_;
  static constexpr ull mod0_ = 2020202077;
  static constexpr ull mod1_ = 2020202111;
  std::vector<ull> hash0_;
  std::vector<ull> hash1_;
  static std::vector<ull> pow0_;
  static std::vector<ull> pow1_;
  static std::mt19937_64 mt_;

  void build() {
    int n = str_.size();
    hash0_.assign(n + 1, 0);
    hash1_.assign(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      hash0_[i + 1] = (hash0_[i] * base0_ + str_[i]) % mod0_;
      hash1_[i + 1] = (hash1_[i] * base1_ + str_[i]) % mod1_;
    }
    for (int i = 0; i < n; ++i) {
      pow0_.emplace_back(pow0_.back() * base0_ % mod0_);
      pow1_.emplace_back(pow1_.back() * base1_ % mod1_);
    }
  }
};

std::mt19937_64 RollingHash::mt_(
    std::chrono::steady_clock::now().time_since_epoch().count());
ull RollingHash::base0_ = std::uniform_int_distribution<ull>(
    2, RollingHash::mod0_ - 1)(RollingHash::mt_);
ull RollingHash::base1_ = std::uniform_int_distribution<ull>(
    2, RollingHash::mod1_ - 1)(RollingHash::mt_);
std::vector<ull> RollingHash::pow0_{1};
std::vector<ull> RollingHash::pow1_{1};
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