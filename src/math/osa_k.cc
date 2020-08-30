// osa_k
// precompute : O(N loglog N), prime factorization query : O(log N)

#include <algorithm>
#include <vector>

// snippet-begin
class osa_k {
  static constexpr int n_ = 1000000 + 5;

 public:
  osa_k() { build(); }

  std::vector<std::pair<int, int>> prime_factor(int n) {
    std::vector<std::pair<int, int>> res;
    while (n != 1) {
      int p = min_factor[n];
      int cnt = 0;
      while (min_factor[n] == p) ++cnt, n /= p;
      res.emplace_back(p, cnt);
    }
    return res;
  }

 private:
  int min_factor[n_ + 1];

  void build() {
    std::fill(min_factor, min_factor + n_ + 1, 0);
    std::vector<int> pr;
    for (int i = 2; i <= n_; ++i) {
      if (!min_factor[i]) {
        min_factor[i] = i;
        pr.emplace_back(i);
      }
      for (int j = 0; j < (int)pr.size() && pr[j] <= min_factor[i] && i * pr[j] <= n_; ++j) {
        min_factor[i * pr[j]] = pr[j];
      }
    }
  }
};
// snippet-end
