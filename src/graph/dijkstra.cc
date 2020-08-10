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
template <class T>
std::vector<T> dijkstra(const graph<T>& g, int s) {
  assert(0 <= s && s < g.n_);
  std::vector<T> dist(g.n_, std::numeric_limits<T>::max());
  using Pair = std::pair<T, int>;
  std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
  dist[s] = 0;
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();
    if (dist[v] < d) continue;
    for (int id : g.data_[v]) {
      const auto& [from, to, cost] = g.edges_[id];
      int nxt = from ^ to ^ v;
      if (dist[nxt] > dist[v] + cost) {
        dist[nxt] = dist[v] + cost;
        pq.emplace(dist[nxt], nxt);
      }
    }
  }
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

  vector<int> dist = dijkstra(g, r);
  for (int e : dist) {
    if (e == numeric_limits<int>::max()) {
      cout << "INF" << '\n';
    } else {
      cout << e << '\n';
    }
  }
}
*/