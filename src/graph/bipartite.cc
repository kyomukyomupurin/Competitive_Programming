// judge whether given graph is bipartite or not
// if given graph is not bipartite, return empty array
// NOT VERIFIED!

#include <queue>
#include <vector>

#include "./graph.cc"

// snippet-begin
template <class T>
std::vector<int> is_bipartite(const graph<T>& g) {
  std::vector<int> side(g.n_, -1);
  std::queue<int> que;
  for (int i = 0; i < g.n_; ++i) {
    if (side[i] != -1) continue;
    que.emplace(i);
    side[i] = 0;
    while (!que.empty()) {
      int cur = que.front();
      que.pop();
      for (int id : g.data_[cur]) {
        const auto& [from, to, cost] = g.edges_[id];
        int nxt = from ^ to ^ cur;
        if (side[nxt] == -1) {
          side[nxt] = side[cur] ^ 1;
          que.emplace(nxt);
        } else {
          if (side[cur] == side[nxt]) return {};
        }
      }
    }
  }
  return side;
}
// snippet-end