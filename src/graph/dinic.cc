// Dinic algorithm
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
//     https://atcoder.jp/contests/abc091/tasks/arc092_a

#include <limits>
#include <queue>
#include <vector>

// snippet-begin
template <class _Tp>
class Dinic {
 public:
  Dinic(int node_size) : node_size_(node_size) { init(); }

  void add(int from, int to, _Tp cost) {
    assert(0 <= from && from < node_size_ && 0 <= to && to < node_size_);
    graph_[from].emplace_back(
        (edge){to, cost, static_cast<int>(graph_[to].size())});
    graph_[to].emplace_back((edge){from, static_cast<_Tp>(0),
                                   static_cast<int>(graph_[from].size()) - 1});
  }

  _Tp max_flow(int s, int t) {
    _Tp flow = 0;
    for (;;) {
      bfs(s);
      if (level_[t] < 0) return flow;
      std::fill(iter_.begin(), iter_.end(), 0);
      _Tp f;
      while ((f = dfs(s, t,
                      std::numeric_limits<_Tp>::max() / static_cast<_Tp>(2))) >
             0) {
        flow += f;
      }
    }
  }

 private:
  struct edge {
    int to;
    _Tp cap;
    int rev;
  };
  int node_size_;
  std::vector<std::vector<edge>> graph_;
  std::vector<int> level_;
  std::vector<int> iter_;

  void init() {
    graph_.resize(node_size_);
    level_.assign(node_size_, 0);
    iter_.assign(node_size_, 0);
  }

  void bfs(int s) {
    std::fill(level_.begin(), level_.end(), -1);
    std::queue<int> que;
    level_[s] = 0;
    que.emplace(s);
    while (!que.empty()) {
      int cur = que.front();
      que.pop();
      for (const edge& next : graph_[cur]) {
        if (next.cap > 0 && level_[next.to] < 0) {
          level_[next.to] = level_[cur] + 1;
          que.emplace(next.to);
        }
      }
    }
  }

  _Tp dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int& i = iter_[v]; i < (int)graph_[v].size(); ++i) {
      edge& e = graph_[v][i];
      if (e.cap > 0 && level_[v] < level_[e.to]) {
        _Tp d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          graph_[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
};
// snippet-end

// verification code
/*
void GRL_6_A() {
  int n, m;
  cin >> n >> m;
  Dinic<int> dinic(n);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    dinic.add(u, v, c);
  }
  cout << dinic.max_flow(0, n - 1) << '\n';
}
*/

/*
void ARC092_A() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i] >> d[i];
  }

  Dinic<int> dinic(2 * n + 2);
  int s = 2 * n, t = 2 * n + 1;

  for (int i = 0; i < n; ++i) {
    dinic.add(s, i, 1);
  }

  for (int i = 0; i < n; ++i) {
    dinic.add(n + i, t, 1);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i] < c[j] && b[i] < d[j]) {
        dinic.add(i, j + n, 1);
      }
    }
  }

  cout << dinic.max_flow(s, t) << '\n';
}
*/