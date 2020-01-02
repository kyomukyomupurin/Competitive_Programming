// Dinic algorithm
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
//     https://atcoder.jp/contests/abc091/tasks/arc092_a

#include <limits>
#include <queue>
#include <vector>

template <class T>
class Dinic {
 public:
  Dinic(int node_size) : node_size_(node_size) { Initialize(); }

  void AddEdge(int from, int to, T cost) {
    graph_[from].push_back({to, cost, static_cast<int>(graph_[to].size())});
    graph_[to].push_back(
        {from, static_cast<T>(0), static_cast<int>(graph_[from].size()) - 1});
  }

  T MaxFlow(int s, int t) {
    T flow = 0;
    for (;;) {
      BFS(s);
      if (level_[t] < 0) return flow;
      std::fill(iter_.begin(), iter_.end(), 0);
      T f;
      while ((f = DFS(s, t, std::numeric_limits<T>::max() / 2)) > 0) {
        flow += f;
      }
    }
  }

 private:
  struct edge {
    int to;
    T cap;
    int rev;
  };
  int node_size_;
  std::vector<std::vector<edge>> graph_;
  std::vector<int> level_;
  std::vector<int> iter_;

  void Initialize() {
    graph_.resize(node_size_);
    level_.assign(node_size_, 0);
    iter_.assign(node_size_, 0);
  }

  void BFS(int s) {
    std::fill(level_.begin(), level_.end(), -1);
    std::queue<int> q;
    level_[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int top = q.front();
      q.pop();
      for (const edge& next : graph_[top]) {
        if (next.cap > 0 && level_[next.to] < 0) {
          level_[next.to] = level_[top] + 1;
          q.push(next.to);
        }
      }
    }
  }

  T DFS(int v, int t, int f) {
    if (v == t) return f;
    for (int& i = iter_[v]; i < graph_[v].size(); ++i) {
      edge& e = graph_[v][i];
      if (e.cap > 0 && level_[v] < level_[e.to]) {
        T d = DFS(e.to, t, min(f, e.cap));
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

// verification code
/*
void GRL_6_A() {
  int n, m; cin >> n >> m;
  Dinic<int> dinic(n);
  for (int i = 0; i < m; ++i) {
    int u, v, c; cin >> u >> v >> c;
    dinic.AddEdge(u, v, c);
  }
  cout << dinic.MaxFlow(0, n - 1) << '\n';
}
*/

/*
void ARC092_A() {
  int n; cin >> n;
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
    dinic.AddEdge(s, i, 1);
  }

  for (int i = 0; i < n; ++i) {
    dinic.AddEdge(n + i, t, 1);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i] < c[j] && b[i] < d[j]) {
        dinic.AddEdge(i, j + n, 1);
      }
    }
  }

  cout << dinic.MaxFlow(s, t) << '\n';
}
*/