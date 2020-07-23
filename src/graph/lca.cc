// LCA(Lowest Common Ancestor)
// verified by
//      https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
//      https://atcoder.jp/contests/abc014/tasks/abc014_4

#include <vector>
#include <cassert>

// snippet-begin
class LCA {
 public:
  LCA(int node_size, int root = 0)
      : node_size_(node_size),
        log_node_(32 - __builtin_clz(node_size_)),
        root_(root) {
    init();
  }

  void add(int u, int v) {
    assert(0 <= u && u < node_size_ && 0 <= v && v < node_size_);
    graph_[u].emplace_back(v);
    graph_[v].emplace_back(u);
  }

  void build() {
    dfs(root_, -1, 0);
    for (int i = 0; i + 1 < log_node_; ++i) {
      for (int j = 0; j < node_size_; ++j) {
        if (par_[i][j] < 0) {
          par_[i + 1][j] = -1;
        } else {
          par_[i + 1][j] = par_[i][par_[i][j]];
        }
      }
    }
  }

  // use after build()
  int lca(int u, int v) {
    assert(0 <= u && u < node_size_ && 0 <= v && v < node_size_);
    if (depth_[u] > depth_[v]) std::swap(u, v);
    for (int i = 0; i < log_node_; ++i) {
      if ((depth_[v] - depth_[u]) >> i & 1) {
        v = par_[i][v];
      }
    }
    if (u == v) return u;
    for (int i = log_node_ - 1; i >= 0; --i) {
      if (par_[i][u] != par_[i][v]) {
        u = par_[i][u];
        v = par_[i][v];
      }
    }
    return par_[0][u];
  }

  int dist(int u, int v) {
    assert(0 <= u && u < node_size_ && 0 <= v && v < node_size_);
    return depth_[u] + depth_[v] - 2 * depth_[lca(u, v)];
  }

 private:
  int node_size_;
  int log_node_;
  int root_;
  std::vector<std::vector<int>> graph_;
  std::vector<std::vector<int>> par_;
  std::vector<int> depth_;

  void dfs(int cur, int prev, int d) {
    par_[0][cur] = prev;
    depth_[cur] = d;
    for (const int& next : graph_[cur]) {
      if (next == prev) continue;
      dfs(next, cur, d + 1);
    }
  }

  void init() {
    depth_.resize(node_size_);
    graph_.resize(node_size_);
    par_.assign(log_node_, std::vector<int>(node_size_, -1));
  }
};
// snippet-end

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
      lca.add(i, c);
    }
  }
  lca.build();
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    cout << lca.lca(u, v) << '\n';
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
    lca.add(x, y);
  }
  lca.build();
  int q; cin >> q;
  for (int i = 0; i < q; ++i) {
    int a, b; cin >> a >> b;
    --a; --b;
    cout << lca.dist(a, b) + 1 << '\n';
  }
}
*/