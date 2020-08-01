// Xorshiro128+ 1.0
// reference : http://prng.di.unimi.it/xoroshiro128plus.c
//             https://cpplover.blogspot.com/2013/03/blog-post_22.html

#include <chrono>
#include <iostream>

// snippet-begin
// This is xorshiro128+ 1.0
// Reference : http://prng.di.unimi.it/xoroshiro128plus.c
class Xoroshiro {
 public:
  Xoroshiro() {
    s[0] = static_cast<uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());
    s[1] = static_cast<uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < (1 << 6); ++i) next();
  }

  using result_type = uint64_t;
  static constexpr uint64_t min() { return std::numeric_limits<result_type>::min(); }
  static constexpr uint64_t max() { return std::numeric_limits<result_type>::max(); }

  uint64_t operator()() { return next(); }

 private:
  uint64_t s[2];

  static inline uint64_t rotl(const uint64_t x, int k) {
    return (x << k) | (x >> (64 - k));
  }

  uint64_t next() {
    const uint64_t s0 = s[0];
    uint64_t s1 = s[1];
    const uint64_t result = s0 + s1;
    s1 ^= s0;
    s[0] = rotl(s0, 24) ^ s1 ^ (s1 << 16);
    s[1] = rotl(s1, 37);

    return result;
  }
};
// snippet-end
