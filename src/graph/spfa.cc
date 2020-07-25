// Shortest Path Faster Algorithm(SPFA)
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B

#include <limits>
#include <queue>
#include <vector>

#include "./graph.cc"

// snippet-begin
template <class T>
std::vector<T> SPFA(const graph<T>& g, int s) {
  assert(0 <= s && s < g.n_);
  std::vector<T> dist(g.n_, std::numeric_limits<T>::max());
  std::vector<int> pend(g.n_, 0);
  std::vector<int> times(g.n_, 0);
  std::queue<int> que;
  que.emplace(s);
  pend[s] = true;
  ++times[s];
  dist[s] = 0;
  while (!que.empty()) {
    int cur = que.front(); que.pop();
    pend[cur] = false;
    for (int id : g.data_[cur]) {
      auto& e = g.edges_[id];
      int nxt = e.from ^ e.to ^ cur;
      T ncost = dist[cur] + e.cost;
      if (ncost >= dist[nxt]) continue;
      dist[nxt] = ncost;
      if (!pend[nxt]) {
        if (++times[nxt] >= g.n_) {
          return {};
        }
        pend[nxt] = true;
        que.emplace(nxt);
      }
    }
  }
  return dist;
}
// snippet-end

// verification code
/*
void GRL_1_B() {
  int n, m, r; cin >> n >> m >> r;
  digraph<int> g(n);
  for (int i = 0; i < m; ++i) {
    int s, t, d; cin >> s >> t >> d;
    g.add(s, t, d);
  }
  vector<int> dist = SPFA(g, r);
  constexpr int kInfinity = numeric_limits<int>::max();
  if (dist.empty()){
    cout << "NEGATIVE CYCLE" << '\n';
  } else {
    for (int e : dist) {
      if (e == kInfinity) {
        cout << "INF" << '\n';
      } else {
        cout << e << '\n';
      }
    }
  }
}
*/