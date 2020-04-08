// Diameter of undirected tree
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A

#include <vector>

template <class _Tp>
class TreeDiameter {
 public:
  TreeDiameter(int node_size) : node_size_(node_size), graph_(node_size_) {}

  void add(int from, int to, _Tp cost) {
    assert(0 <= from && from < node_size_ && 0 <= to && to < node_size_);
    graph_[from].emplace_back((edge){cost, to});
    graph_[to].emplace_back((edge){cost, from});
  }

  _Tp get() { return bfs(bfs(0).second).first; }

 private:
  struct edge {
    _Tp cost;
    int to;
  };
  int node_size_;
  std::vector<std::vector<edge>> graph_;

  std::pair<_Tp, int> bfs(int source) {
    std::pair<_Tp, int> result = {static_cast<_Tp>(0), 0};
    std::queue<int> que;
    bool visited[node_size_] = {};
    vector<_Tp> dist(node_size_, 0);
    visited[source] = true;
    que.emplace(source);
    while (!que.empty()) {
      int cur = que.front();
      que.pop();
      for (const auto& next : graph_[cur]) {
        if (visited[next.to]) continue;
        visited[next.to] = true;
        dist[next.to] += dist[cur] + next.cost;
        que.emplace(next.to);
        result = std::max(result, {dist[next.to], next.to});
      }
    }
    return result;
  }
};

// verification code
/*
void GRL_5_A() {
  int n;
  cin >> n;
  TreeDiameter<int> td(n);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w;
    cin >> s >> t >> w;
    td.add(s, t, w);
  }
  cout << td.get() << '\n';
}
*/