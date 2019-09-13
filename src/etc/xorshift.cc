/**
 *  Xorshift128+
**/

#include <chrono>
#include <iostream>

// reference : https://cpplover.blogspot.com/2013/03/blog-post_22.html
//             http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3551.pdf
//             https://arxiv.org/pdf/1810.05313.pdf
// verified by https://atcoder.jp/contests/abc139/tasks/abc139_f
class Xorshift128plus {
 public:
  Xorshift128plus() { Initialize(); }
  using result_type = uint64_t;
  static constexpr uint64_t min() {
    return std::numeric_limits<result_type>::min();
  }
  static constexpr uint64_t max() {
    return std::numeric_limits<result_type>::max();
  }
  uint64_t operator()() { return GetNext(); }

 private:
  static uint64_t result_;
  static uint64_t seed0_;
  static uint64_t seed1_;
  void Next();
  void Initialize();
  uint64_t GetNext();
};

uint64_t Xorshift128plus::result_;
uint64_t Xorshift128plus::seed0_ = static_cast<uint64_t>(
    std::chrono::steady_clock::now().time_since_epoch().count());
uint64_t Xorshift128plus::seed1_ = static_cast<uint64_t>(
    std::chrono::steady_clock::now().time_since_epoch().count());

void Xorshift128plus::Initialize() {
  for (int i = 0; i < 40; ++i) {
    Next();
  }
}

void Xorshift128plus::Next() {
  uint64_t s1 = seed0_;
  uint64_t s0 = seed1_;
  result_ = s0 + s1;
  seed0_ = s0;
  s1 ^= s1 << 23;
  seed1_ = s1 ^ s0 ^ (s1 >> 18) ^ (s0 >> 5);
}

uint64_t Xorshift128plus::GetNext() {
  Next();
  return result_;
}