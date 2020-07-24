// Dijkstra algorithm
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>

#include "./graph.cc"

template <class T>
using binary_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

// snippet-begin
template <class _Tp>
std::vector<_Tp> dijkstra(const graph<_Tp>& g, int s) {
  assert(0 <= s && s < g.n_);
  std::vector<_Tp> dist(g.n_, std::numeric_limits<_Tp>::max());
  binary_heap<std::pair<_Tp, int>> pq;
  dist[s] = 0;
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();
    if (dist[v] < d) continue;
    for (int id : g.data_[v]) {
      auto& e = g.edges_[id];
      int nxt = e.from ^ e.to ^ v;
      if (dist[nxt] > dist[v] + e.cost) {
        dist[nxt] = dist[v] + e.cost;
        pq.emplace(dist[nxt], nxt);
      }
    }
  }
  std::replace(dist.begin(), dist.end(), std::numeric_limits<_Tp>::max(), -1);
  return dist;
}
// snippet-end

// verification code
/*
void GRL_1_A() {
  int n, m, r; cin >> n >> m >> r;
  digraph<int> g(n);
  for (int i = 0; i < m; ++i) {
    int s, t, d; cin >> s >> t >> d;
    g.add(s, t, d);
  }
p
  vector<int> dist = dijkstra(g, r);
  for (int e : dist) {
    if (e == -1) {
      cout << "INF" << '\n';
    } else {
      cout << e << '\n';
    }
  }
}
*/