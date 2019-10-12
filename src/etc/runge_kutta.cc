/**
 *  Runge Kutta algorithm
**/

#include <functional>
#include <vector>

class RungeKutta {
  using ld = long double;

 public:
  RungeKutta(std::function<ld(ld, ld)> func, const ld& initial_time,
             const ld& initial_y, const ld& time_span, const int& step_number)
      : func_(func),
        time_span_(time_span),
        step_number_(step_number),
        initial_time_(initial_time),
        initial_y_(initial_y) {}
  struct status {
    ld next_time, next_y;
  };
  std::vector<status> Solve();

 private:
  std::function<ld(ld, ld)> func_;
  const ld time_span_;
  const int step_number_;
  const ld initial_time_;
  const ld initial_y_;
  status Proceed(const ld& t, const ld& y);
};

std::vector<RungeKutta::status> RungeKutta::Solve() {
  std::vector<RungeKutta::status> result(step_number_ + 1);
  result[0] = {initial_time_, initial_y_};
  for (int i = 1; i <= step_number_; ++i) {
    result[i] = Proceed(result[i - 1].next_time, result[i - 1].next_y);
  }

  return result;
}

RungeKutta::status RungeKutta::Proceed(const ld& t, const ld& y) {
  ld k1 = func_(t, y);
  ld k2 = func_(t + time_span_ / 2.0, y + time_span_ / 2.0 * k1);
  ld k3 = func_(t + time_span_ / 2.0, y + time_span_ / 2.0 * k2);
  ld k4 = func_(t + time_span_, y + time_span_ * k3);
  return {t + time_span_, y + time_span_ * (k1 + 2.0 * (k2 + k3) + k4) / 6.0};
}

/*
auto f = [](long double t, long double y){ return y * cos(t); };
RungeKutta rk(f, 0.0, 1.0, 0.5, 20);
vector<RungeKutta::status> vec = rk.Solve();
*/