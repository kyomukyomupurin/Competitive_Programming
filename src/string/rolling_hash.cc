/**
 *  Rolling Hash
**/

#include <chrono>
#include <string>
#include <vector>
#include <ext/random>

using ull = unsigned long long;

// verified by
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B
// https://atcoder.jp/contests/abc141/tasks/abc141_e
class RollingHash {
 public:
  RollingHash(const std::string& s) : s_(s) { Initialize(); }
  std::pair<ull, ull> GetHash(int left, int right);

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
  static __gnu_cxx::sfmt19937_64 sfmt_;
  void Initialize();
};

void RollingHash::Initialize() {
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

// return hash pair of [left, right)
inline std::pair<ull, ull> RollingHash::GetHash(int left, int right) {
  ull ret0 =
      hash0_[right] + mod0_ - hash0_[left] * power0_[right - left] % mod0_;
  if (ret0 >= mod0_) ret0 -= mod0_;
  ull ret1 =
      hash1_[right] + mod1_ - hash1_[left] * power1_[right - left] % mod1_;
  if (ret1 >= mod1_) ret1 -= mod1_;

  return {ret0, ret1};
}

__gnu_cxx::sfmt19937_64 RollingHash::sfmt_(
    std::chrono::steady_clock::now().time_since_epoch().count());
ull RollingHash::base0_ = std::uniform_int_distribution<ull>(
    2, RollingHash::mod0_)(RollingHash::sfmt_);
ull RollingHash::base1_ = std::uniform_int_distribution<ull>(
    2, RollingHash::mod1_)(RollingHash::sfmt_);
std::vector<ull> RollingHash::power0_{1};
std::vector<ull> RollingHash::power1_{1};