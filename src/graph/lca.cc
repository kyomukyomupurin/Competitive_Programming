// LCA(Lowest Common Ancestor)
// verified by
//      https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
//      https://atcoder.jp/contests/abc014/tasks/abc014_4

#include <vector>

class LCA {
 public:
  LCA(int node_size, int root = 0)
      : node_size_(node_size), log_node_(std::__lg(node_size) + 1), root_(root) {
    Initialize();
  }

  void Add_Edge(int u, int v) {
    graph_[u].emplace_back(v);
    graph_[v].emplace_back(u);
  }

  void Build() {
    DFS(root_, -1, 0);
    for (int i = 0; i + 1 < log_node_; ++i) {
      for (int j = 0; j < node_size_; ++j) {
        if (parent_[i][j] < 0) {
          parent_[i + 1][j] = -1;
        } else {
          parent_[i + 1][j] = parent_[i][parent_[i][j]];
        }
      }
    }
  }

  // use after Build()
  int GetLCA(int u, int v) {
    if (depth_[u] > depth_[v]) std::swap(u, v);
    for (int i = 0; i < log_node_; ++i) {
      if ((depth_[v] - depth_[u]) >> i & 1) {
        v = parent_[i][v];
      }
    }
    if (u == v) return u;
    for (int i = log_node_ - 1; i >= 0; --i) {
      if (parent_[i][u] != parent_[i][v]) {
        u = parent_[i][u];
        v = parent_[i][v];
      }
    }
    return parent_[0][u];
  }

  int GetDist(int u, int v) {
    return depth_[u] + depth_[v] - 2 * depth_[GetLCA(u, v)];
  }

 private:
  int node_size_;
  int log_node_;
  int root_;
  std::vector<std::vector<int>> graph_;
  std::vector<std::vector<int>> parent_;
  std::vector<int> depth_;

  void DFS(int cur, int prev, int d) {
    parent_[0][cur] = prev;
    depth_[cur] = d;
    for (const int& next : graph_[cur]) {
      if (next == prev) continue;
      DFS(next, cur, d + 1);
    }
  }

  void Initialize() {
    depth_.resize(node_size_);
    graph_.resize(node_size_);
    parent_.assign(log_node_, std::vector<int>(node_size_, -1));
  }
};

// verification code
/*
void GRL_5_C() {
  int n;
  cin >> n;
  LCA lca(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int c;
      cin >> c;
      lca.Add_Edge(i, c);
    }
  }
  lca.Build();
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    cout << lca.GetLCA(u, v) << '\n';
  }
}
*/
/*
void ABC_14_D() {
  int n; cin >> n;
  LCA lca(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y; cin >> x >> y;
    --x; --y;
    lca.Add_Edge(x, y);
  }
  lca.Build();
  int q; cin >> q;
  for (int i = 0; i < q; ++i) {
    int a, b; cin >> a >> b;
    --a; --b;
    cout << lca.GetDist(a, b) + 1 << '\n';
  }
}
*/