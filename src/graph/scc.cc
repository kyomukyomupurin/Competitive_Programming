// Strongly Connected Component

#include <vector>

#include "./graph.cc"

// snippet-begin
template <class T>
std::vector<std::vector<int>> SCC(const digraph<T>& g) {
  std::vector<int> order;
  std::vector<bool> visited(g.n_, false);

  auto dfs = [&](auto&& self, int cur) -> void {
    visited[cur] = true;
    for (int id : g.data_[cur]) {
      const auto& [from, to, cost] = g.edges_[id];
      int nxt = from ^ to ^ cur;
      if (visited[nxt]) continue;
      self(self, nxt);
    }
    order.emplace_back(cur);
  };

  for (int i = 0; i < g.n_; ++i) {
    if (!visited[i]) dfs(dfs, i);
  }

  visited.assign(g.n_, false);
  std::vector<std::vector<int>> scc(g.n_);
  digraph<T> rg = g.reverse();

  auto dfs2 = [&](auto&& self, int cur, int k) -> void {
    visited[cur] = true;
    scc[k].emplace_back(cur);
    for (int id : rg.data_[cur]) {
      const auto& [from, to, cost] = rg.edges_[id];
      int nxt = from ^ to ^ cur;
      if (visited[nxt]) continue;
      self(self, nxt, k);
    }
  };

  int cnt = 0;

  for (int i = int(order.size()) - 1; i >= 0; --i) {
    if (!visited[order[i]]) dfs2(dfs2, order[i], cnt++);
  }

  scc.resize(cnt);

  return scc;
}
// snippet-end