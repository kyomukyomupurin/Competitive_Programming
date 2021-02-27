// Traveling salesman problem

#include "./graph.cc"

#include <numeric>
#include <vector>

template <class T>
T TSP(const graph<T>& g) {
  int n = g.n_;
  constexpr T kInfinity = std::numeric_limits<T>::max() / 2;
  std::vector dp(1 << n, std::vector(n, kInfinity));
  dp[0][0] = 0;

  for (int bit = 0; bit < (1 << n); ++bit) {
    for (int cur = 0; cur < n; ++cur) {
      for (int id : g.data_[cur]) {
        const auto& [from, to, cost] = g.edges_[id];
        int nxt = from ^ to ^ cur;
        if ((bit >> nxt) & 1) continue;
        dp[bit | (1 << nxt)][nxt] =
            std::min(dp[bit | (1 << nxt)][nxt], dp[bit][cur] + cost);
      }
    }
  }

  T shortest_path = dp[(1 << n) - 1][0];
  if (shortest_path == kInfinity) shortest_path = -1;

  return shortest_path;
}