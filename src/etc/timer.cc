// Timer
// verified by
//     https://atcoder.jp/contests/abc139/tasks/abc139_f

#include <chrono>
// snippet-begin
class Timer {
 public:
  // (second)
  double GetElapsedTime() {
    return static_cast<double>(GetCycle() - start_) /
           static_cast<double>(clock_frequency_);
  }

  void Start() { start_ = GetCycle(); }

 private:
  int64_t start_;
  static constexpr int64_t clock_frequency_ = 2800000000;

  int64_t GetCycle() {
    uint32_t low, high;
    __asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
    return (static_cast<int64_t>(low)) | (static_cast<int64_t>(high) << 32);
  }
};
// snippet-end
