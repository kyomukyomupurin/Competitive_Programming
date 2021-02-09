// modint

#include <algorithm>
#include <cassert>
#include <iostream>

using int64 = long long;

// snippet-begin
template <class T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    std::swap(a, m);
    u -= t * v;
    std::swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <int Mod>
class Modular {
 public:
  constexpr Modular(int64 val = 0) : val_(val % mod()) {
    if (val_ < 0) val_ += mod();
  }

  const int64& operator()() const noexcept { return val_; }

  constexpr int mod() const noexcept { return Mod; }

  constexpr Modular& operator+=(const Modular& other) noexcept {
    if ((val_ += other.val_) >= mod()) val_ -= mod();
    return *this;
  }

  constexpr Modular& operator-=(const Modular& other) noexcept {
    if ((val_ -= other.val_) < 0) val_ += mod();
    return *this;
  }

  constexpr Modular& operator*=(const Modular& other) noexcept {
    (val_ *= other.val_) %= mod();
    if (val_ < 0) val_ += mod();
    return *this;
  }

  constexpr Modular& operator/=(const Modular& other) noexcept {
    return *this *= Modular(inverse(other.val_, static_cast<int64>(mod())));
  }

  constexpr Modular& operator++() noexcept { return *this += 1; }

  constexpr Modular& operator--() noexcept { return *this -= 1; }

  constexpr Modular operator-() const noexcept { return Modular(-val_); }

  friend std::istream& operator>>(std::istream& is, Modular& num) {
    int64 x;
    is >> x;
    num = Modular(x);
    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const Modular& num) {
    return os << num();
  }

 private:
  int64 val_;
};

constexpr int mod = (int)1e9 + 7;
using Mint = Modular<mod>;

Mint operator+(const Mint& lhs, const Mint& rhs) noexcept {
  return Mint(lhs) += rhs;
}

Mint operator-(const Mint& lhs, const Mint& rhs) noexcept {
  return Mint(lhs) -= rhs;
}

Mint operator*(const Mint& lhs, const Mint& rhs) noexcept {
  return Mint(lhs) *= rhs;
}

Mint operator/(const Mint& lhs, const Mint& rhs) noexcept {
  return Mint(lhs) /= rhs;
}

bool operator==(const Mint& lhs, const Mint& rhs) noexcept {
  return lhs() == rhs();
}

bool operator!=(const Mint& lhs, const Mint& rhs) noexcept {
  return !(lhs() == rhs());
}

template <class T>
Mint power(const Mint& a, T b) {
  assert(b >= 0);
  Mint x = a, res = 1;
  while (b) {
    if (b & 1) res *= x;
    x *= x;
    b >>= 1;
  }
  return res;
}

// 必要なところまで作る組み合わせテーブル
// inv を別の場所で使いたい、とかのときは最初に choose(2000000, 1); とか空呼び出ししてテーブルを十分なサイズまで作っておく
// std::vector<Mint> fact{1, 1};
// std::vector<Mint> inv{0, 1};
// std::vector<Mint> finv{1, 1};

// Mint choose(int n, int k) noexcept {
//   if (n < k || n < 0 || k < 0) return 0;
//   while ((int)fact.size() < n + 1) {
//     fact.emplace_back(fact.back() * (int)fact.size());
//     inv.emplace_back(mod - inv[mod % ((int)fact.size() - 1)] * (mod / ((int)fact.size() - 1)));
//     finv.emplace_back(finv.back() * inv.back());
//   }
//   return fact[n] * finv[k] * finv[n - k];
// }
// snippet-end