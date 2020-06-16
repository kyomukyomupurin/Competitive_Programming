// Sieve of Eratosthenes with linear time complexity
// reference:
//     https://cp-algorithms.com/algebra/prime-sieve-linear.html

#include <array>
#include <vector>
// snippet-begin
std::vector<int> LinearTimeSieve() {
  constexpr int n = 1000000;
  std::array<int, n + 1> lp;
  std::fill(lp.begin(), lp.end(), 0);
  std::vector<int> pr;
  for (int i = 2; i <= n; ++i) {
    if (!lp[i]) {
      lp[i] = i;
      pr.emplace_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= n;
         ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
  return pr;
}
// snippet-end
