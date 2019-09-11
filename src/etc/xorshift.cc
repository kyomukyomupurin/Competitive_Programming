/**
 *  Xorshift128+
**/

#include <chrono>
#include <iostream>

// verified by https://atcoder.jp/contests/abc139/tasks/abc139_f
class Xorshift128plus {
 public:
  Xorshift128plus(
      uint64_t seed0 =
          std::chrono::steady_clock::now().time_since_epoch().count() -
          172817281728,
      uint64_t seed1 =
          std::chrono::steady_clock::now().time_since_epoch().count() +
          172817281728)
      : seed0_(seed0), seed1_(seed1) {}
  void Initialize();
  int RandomInt(int a, int b);
  long long RandomInt64(long long a, long long b);
  double RandomDouble(double a, double b);

 private:
  static uint64_t result_;
  uint64_t seed0_;
  uint64_t seed1_;
  void Next();
};

uint64_t Xorshift128plus::result_;

void Xorshift128plus::Next() {
  uint64_t s1 = seed0_;
  uint64_t s0 = seed1_;
  result_ = s0 + s1;
  seed0_ = s0;
  s1 ^= s1 << 23;
  seed1_ = s1 ^ s0 ^ (s1 >> 18) ^ (s0 >> 5);
}

void Xorshift128plus::Initialize() {
  for (int i = 0; i < 10; ++i) {
    Next();
  }
}

// return [a, b - 1]
int Xorshift128plus::RandomInt(int a, int b) {
  Next();
  return static_cast<int>(
      result_ % (static_cast<uint64_t>(b) - static_cast<uint64_t>(a)) +
      static_cast<uint64_t>(a));
}

long long Xorshift128plus::RandomInt64(long long a, long long b) {
  Next();
  return static_cast<long long>(
      result_ % (static_cast<uint64_t>(b) - static_cast<uint64_t>(a)) +
      static_cast<uint64_t>(a));
}

// return [a, b]
double Xorshift128plus::RandomDouble(double a, double b) {
  Next();
  return static_cast<double>(result_) / static_cast<double>(UINT64_MAX) *
             (b - a) + a;
}