// Golden section search algorithm
// verified by
//     https://atcoder.jp/contests/arc054/tasks/arc054_b

#include <cmath>

// snippet-begin
template <class F>
double GoldenSectionSearch(double low, double high, F f) {
  constexpr double phi = (1 + std::sqrt(5)) / 2;
  double c1 = (phi * low + high) / (1 + phi);
  double c2 = (low + phi * high) / (1 + phi);
  double cache_f1 = f(c1), cache_f2 = f(c2);

  for (int i = 0; i < 150; ++i) {
    if (cache_f1 > cache_f2) {
      low = c1;
      cache_f1 = cache_f2;
      c1 = c2;
      c2 = (low + phi * high) / (1 + phi);
      cache_f2 = f(c2);
    } else {
      high = c2;
      cache_f2 = cache_f1;
      c2 = c1;
      c1 = (phi * low + high) / (1 + phi);
      cache_f1 = f(c1);
    }
  }

  return (low + high) / 2;
}
// snippet-end

// verification code
/*
void ARC54_B() {
  double p; cin >> p;
  auto f = [&](double x) { return x + p * (pow(0.5, (x / 1.5))); };
  cout << fixed << setprecision(17) << f(GoldenSectionSearch(0, p, f)) << '\n';
}
*/
