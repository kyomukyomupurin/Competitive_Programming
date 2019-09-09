/**
 *  Timer
**/

#include <chrono>

// verified by https://atcoder.jp/contests/abc139/tasks/abc139_f
class Timer {
 public:
  Timer(std::chrono::system_clock::time_point start =
            std::chrono::system_clock::now(),
        std::chrono::system_clock::time_point stop =
            std::chrono::system_clock::now())
      : start_(start), stop_(stop) {}
  void Start();
  void Stop();
  double GetElapsedTime();

 private:
  std::chrono::system_clock::time_point start_;
  std::chrono::system_clock::time_point stop_;
};

void Timer::Start() { start_ = std::chrono::system_clock::now(); }

void Timer::Stop() { stop_ = std::chrono::system_clock::now(); }

double Timer::GetElapsedTime() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(stop_ - start_)
      .count();
}