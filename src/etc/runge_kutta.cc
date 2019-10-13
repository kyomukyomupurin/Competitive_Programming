/**
 *  Runge Kutta algorithm
**/

#include <fstream>
#include <functional>
#include <vector>

class RungeKutta {
  using ld = long double;

 public:
  RungeKutta(std::function<ld(ld, ld)> func, const ld& initial_time,
             const ld& initial_y, const ld& time_span, const int& step_number)
      : func_(func),
        step_number_(step_number),
        time_span_(time_span),
        initial_time_(initial_time),
        initial_y_(initial_y) {
          result_.resize(step_number_ + 1);
        }
  struct status {
    ld next_time, next_y;
  };
  void Solve();
  void Output();

 private:
  std::function<ld(ld, ld)> func_;
  std::vector<RungeKutta::status> result_;
  const int step_number_;
  const ld time_span_;
  const ld initial_time_;
  const ld initial_y_;
  status Proceed(const ld& t, const ld& y);
};

void RungeKutta::Solve() {
  result_[0] = {initial_time_, initial_y_};
  for (int i = 1; i <= step_number_; ++i) {
    result_[i] = Proceed(result_[i - 1].next_time, result_[i - 1].next_y);
  }

  return;
}

void RungeKutta::Output() {
  std::ofstream outputfile("output.txt");
  for (int i = 0; i <= step_number_; ++i) {
    outputfile << result_[i].next_time << " " << result_[i].next_y << '\n';
  }
  outputfile.close();
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
rk.Solve();
rk.Output();
*/