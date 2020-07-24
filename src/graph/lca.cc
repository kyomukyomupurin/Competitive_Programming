// LCA(Lowest Common Ancestor)
// verified by
//      https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
//      https://atcoder.jp/contests/abc014/tasks/abc014_4

#include <vector>
#include <cassert>

#include "./graph.cc"

// snippet-begin
template <class T>
class lca_forest : public forest<T> {
 public:
  using forest<T>::n_;
  using forest<T>::data_;
  using forest<T>::edges_;

  lca_forest(int n, int r = 0)
      : forest<T>(n), lg_(32 - __builtin_clz(n)), r_(r) {
    init();
  }

  void add(int from, int to, T cost = 1) {
    int id = edges_.size();
    data_[from].emplace_back(id);
    data_[to].emplace_back(id);
    edges_.push_back({from, to, cost});
  }

  void build() {
    dfs(r_, -1, 0);
    for (int i = 0; i + 1 < lg_; ++i) {
      for (int j = 0; j < n_; ++j) {
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
    assert(0 <= u && u < n_ && 0 <= v && v < n_);
    if (dep_[u] > dep_[v]) std::swap(u, v);
    for (int i = 0; i < lg_; ++i) {
      if ((dep_[v] - dep_[u]) >> i & 1) {
        v = par_[i][v];
      }
    }
    if (u == v) return u;
    for (int i = lg_ - 1; i >= 0; --i) {
      if (par_[i][u] != par_[i][v]) {
        u = par_[i][u];
        v = par_[i][v];
      }
    }
    return par_[0][u];
  }

  int dist(int u, int v) {
    assert(0 <= u && u < n_ && 0 <= v && v < n_);
    return dep_[u] + dep_[v] - 2 * dep_[lca(u, v)];
  }

 private:
  int lg_;
  int r_;
  std::vector<std::vector<int>> par_;
  std::vector<int> dep_;

  void dfs(int cur, int pre, int d) {
    par_[0][cur] = pre;
    dep_[cur] = d;
    for (int id : data_[cur]) {
      auto& e = edges_[id];
      int nxt = e.to ^ e.from ^ cur;
      if (nxt == pre) continue;
      dfs(nxt, cur, d + 1);
    }
  }

  void init() {
    dep_.resize(n_);
    par_.assign(lg_, std::vector<int>(n_, -1));
  }
};
// snippet-end

// verification code
/*
void GRL_5_C() {
  int n;
  cin >> n;
  lca_forest<int> lca(n);
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
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << lca.lca(u, v) << '\n';
  }
}
*/
/*
void ABC_14_D() {
  int n; cin >> n;
  lca_forest<int> lca(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y; cin >> x >> y;
    --x; --y;
    lca.add(x, y);
  }
  lca.build();
  int q; cin >> q;
  while (q--) {
    int a, b; cin >> a >> b;
    --a; --b;
    cout << lca.dist(a, b) + 1 << '\n';
  }
}
*/