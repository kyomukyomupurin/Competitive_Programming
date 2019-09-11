/**
 *  Timer
**/

#include <chrono>

// verified by https://atcoder.jp/contests/abc139/tasks/abc139_f
class Timer {
 public:
  void Start();
  void Stop();
  double GetElapsedTime();

 private:
  static std::chrono::system_clock::time_point start_;
  static std::chrono::system_clock::time_point stop_;
};

std::chrono::system_clock::time_point Timer::start_;
std::chrono::system_clock::time_point Timer::stop_;

void Timer::Start() { start_ = std::chrono::system_clock::now(); }

void Timer::Stop() { stop_ = std::chrono::system_clock::now(); }

double Timer::GetElapsedTime() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(stop_ - start_)
      .count();
}