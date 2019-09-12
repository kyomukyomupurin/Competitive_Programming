/**
 *  Generate random number
**/

#include <chrono>
#include <ext/random>
#include <random>

// verified by https://atcoder.jp/contests/abc139/tasks/abc139_f
class RandomNumberGenerator {
 public:
  RandomNumberGenerator()
      : rng_(std::chrono::steady_clock::now().time_since_epoch().count()) {}
  int RandomInt(int a, int b);
  long long RandomInt64(long long a, long long b);
  double RandomDouble(double a, double b);

 private:
  __gnu_cxx::sfmt19937_64 rng_;
};

// return [a, b]
inline int RandomNumberGenerator::RandomInt(int a, int b) {
  std::uniform_int_distribution<int> distribution(a, b);
  return distribution(rng_);
}

inline long long RandomNumberGenerator::RandomInt64(long long a, long long b) {
  std::uniform_int_distribution<long long> distribution(a, b);
  return distribution(rng_);
}

inline double RandomNumberGenerator::RandomDouble(double a, double b) {
  std::uniform_real_distribution<double> distribution(a, b);
  return distribution(rng_);
}