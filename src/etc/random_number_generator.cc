/**
 *  Generate random number
**/

#include <chrono>
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
  std::mt19937_64 rng_;
};

// return [a, b]
int RandomNumberGenerator::RandomInt(int a, int b) {
  std::uniform_int_distribution<int> distribution(a, b);
  return distribution(rng_);
}

long long RandomNumberGenerator::RandomInt64(long long a, long long b) {
  std::uniform_int_distribution<long long> distribution(a, b);
  return distribution(rng_);
}

double RandomNumberGenerator::RandomDouble(double a, double b) {
  std::uniform_real_distribution<double> distribution(a, b);
  return distribution(rng_);
}