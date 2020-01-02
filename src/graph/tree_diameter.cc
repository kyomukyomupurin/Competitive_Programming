// Diameter of undirected tree
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A

#include <vector>

template <class T>
class TreeDiameter {
 public:
  TreeDiameter(int node_size) : node_size_(node_size) { Initialize(); }

  void AddEdge(int from, int to, T cost) {
    graph_[from].push_back({cost, to});
    graph_[to].push_back({cost, from});
  }

  T GetDiameter() { return BFS(BFS(0).second).first; }

 private:
  struct edge {
    T cost;
    int to;
  };
  int node_size_;
  std::vector<std::vector<edge>> graph_;

  void Initialize() { graph_.resize(node_size_); }

  std::pair<T, int> BFS(int source) {
    std::pair<T, int> result = {static_cast<T>(0), 0};
    std::queue<int> q;
    bool visited[node_size_] = {};
    vector<T> dist(node_size_, 0);
    visited[source] = true;
    q.push(source);
    while (!q.empty()) {
      int top = q.front();
      q.pop();
      for (const auto& next : graph_[top]) {
        if (visited[next.to]) continue;
        visited[next.to] = true;
        dist[next.to] += dist[top] + next.cost;
        q.push(next.to);
        result = max(result, {dist[next.to], next.to});
      }
    }
    return result;
  }
};

// verification code
/*
void GRL_5_A() {
  int n; cin >> n;
  TreeDiameter<int> td(n);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, w; cin >> s >> t >> w;
    td.AddEdge(s, t, w);
  }
  cout << td.GetDiameter() << '\n';
}
*/