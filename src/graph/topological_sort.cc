// Topological Sort
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B

#include <algorithm>
#include <vector>
#include <queue>

#include "./graph.cc"

// snippet-begin
template <class T>
std::vector<int> topological_sort(const digraph<T>& g) {
  std::vector<int> lev(g.n_, 0);
  std::vector<int> res;
  for (auto e : g.edges_) ++lev[e.to];
  std::queue<int> que;
  for (int i = 0; i < g.n_; ++i) {
    if (lev[i] == 0) que.emplace(i);
  }
  while (!que.empty()) {
    int cur = que.front(); que.pop();
    res.emplace_back(cur);
    for (int id : g.data_[cur]) {
      auto& e = g.edges_[id];
      int nxt = e.from ^ e.to ^ cur;
      if (--lev[nxt] == 0) que.emplace(nxt);
    }
  }
  if (std::all_of(lev.begin(), lev.end(), [](int e){ return e == 0; })) {
    return res;
  } else {
    return {};
  }
}
// snippet-end

// verification code
/*
void GRL_4_B() {
  int n, m; cin >> n >> m;
  digraph<int> g(n);
  for (int i = 0; i < m; ++i) {
    int s, t; cin >> s >> t;
    g.add(s, t);
  }
  vector<int> ts = topological_sort(g);
  for (int e : ts) cout << e << '\n';
}
*/