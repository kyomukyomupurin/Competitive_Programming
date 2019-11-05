/**
 *  Timer
**/

#include <chrono>

// verified by https://atcoder.jp/contests/abc139/tasks/abc139_f
class Timer {
 public:
  double GetElapsedTime();
  void Start();

 private:
  int64_t start_;
  static constexpr int64_t clock_frequency_ = 2800000000;
  int64_t GetCycle();
};

double Timer::GetElapsedTime() {
  return static_cast<double>(GetCycle() - start_) /
         static_cast<double>(clock_frequency_);
}

void Timer::Start() { start_ = GetCycle(); }

int64_t Timer::GetCycle() {
  uint32_t low, high;
  __asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
  return (static_cast<int64_t>(low)) | (static_cast<int64_t>(high) << 32);
}