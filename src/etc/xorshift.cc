// Xorshift128+
// reference :
//     https://cpplover.blogspot.com/2013/03/blog-post_22.html
//     http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3551.pdf
//     https://arxiv.org/pdf/1810.05313.pdf
// verified by
//     https://atcoder.jp/contests/abc139/tasks/abc139_f

#include <chrono>
#include <iostream>
// snippet-begin
class Xorshift {
 public:
  Xorshift() {
    seed0_ = static_cast<uint64_t>(
        std::chrono::steady_clock::now().time_since_epoch().count());
    seed1_ = static_cast<uint64_t>(
        std::chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < 100; ++i) {
      GetNext();
    }
  }
  using result_type = uint64_t;
  static constexpr uint64_t min() {
    return std::numeric_limits<result_type>::min();
  }
  static constexpr uint64_t max() {
    return std::numeric_limits<result_type>::max();
  }

  uint64_t operator()() { return GetNext(); }

 private:
  uint64_t result_;
  uint64_t seed0_;
  uint64_t seed1_;

  uint64_t GetNext() {
    uint64_t s1 = seed0_;
    uint64_t s0 = seed1_;
    result_ = s0 + s1;
    seed0_ = s0;
    s1 ^= s1 << 23;
    seed1_ = s1 ^ s0 ^ (s1 >> 18) ^ (s0 >> 5);
    return result_;
  }
};
// snippet-end
