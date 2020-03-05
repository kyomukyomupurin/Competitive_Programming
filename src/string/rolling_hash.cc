// Rolling Hash
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B
//     https://atcoder.jp/contests/abc141/tasks/abc141_e

#include <chrono>
#include <string>
#include <vector>
#include <random>

using ull = unsigned long long;

class RollingHash {
 public:
  RollingHash(const std::string& s) : s_(s) { Initialize(); }

  // get hash value of [left, right)
  std::pair<ull, ull> GetHash(int left, int right) {
    ull ret0 =
        (hash0_[right] - hash0_[left] * power0_[right - left] % mod0_ + mod0_) %
        mod0_;
    ull ret1 =
        (hash1_[right] - hash1_[left] * power1_[right - left] % mod1_ + mod1_) %
        mod1_;
    return {ret0, ret1};
  }

 private:
  const std::string s_;
  static ull base0_;
  static ull base1_;
  static constexpr ull mod0_ = 2020202077;
  static constexpr ull mod1_ = 2020202111;
  std::vector<ull> hash0_;
  std::vector<ull> hash1_;
  static std::vector<ull> power0_;
  static std::vector<ull> power1_;
  static std::mt19937_64 mt_;

  void Initialize() {
    size_t n = s_.size();
    hash0_.assign(n + 1, 0);
    hash1_.assign(n + 1, 0);
    for (size_t i = 0; i < n; ++i) {
      hash0_[i + 1] = (hash0_[i] * base0_ + s_[i]) % mod0_;
      hash1_[i + 1] = (hash1_[i] * base1_ + s_[i]) % mod1_;
    }
    while (power0_.size() <= n) {
      power0_.emplace_back(power0_.back() * base0_ % mod0_);
      power1_.emplace_back(power1_.back() * base1_ % mod1_);
    }
  }
};

std::mt19937_64 RollingHash::mt_(
    std::chrono::steady_clock::now().time_since_epoch().count());
ull RollingHash::base0_ =
    std::uniform_int_distribution<ull>(2, RollingHash::mod0_)(RollingHash::mt_);
ull RollingHash::base1_ =
    std::uniform_int_distribution<ull>(2, RollingHash::mod1_)(RollingHash::mt_);
std::vector<ull> RollingHash::power0_{1};
std::vector<ull> RollingHash::power1_{1};

// verification code
/*
void ABC141_E() {
  int n; cin >> n;
  string s; cin >> s;
  RollingHash rh(s);

  auto ok = [&](int x) -> bool{
    for (int i = 0; i + 2 * x <= n; ++i) {
      for (int j = i + x; j + x <= n; ++j) {
        if (rh.GetHash(i, i + x) == rh.GetHash(j, j + x)) {
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
  string t, p; cin >> t >> p;
  RollingHash rh0(t);
  RollingHash rh1(p);

  int n = t.size(); int m = p.size();

  for (int i = 0; i + m <= n; ++i) {
    if (rh0.GetHash(i, i + m) == rh1.GetHash(0, m)) {
      cout << i << '\n';
    }
  }  
}
*/