/**
 *  dinic algorithm
**/

#include <limits>
#include <queue>
#include <vector>

// verified by https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
template <typename T>
class Dinic {
 public:
  Dinic(const int& node_size) : node_size_(node_size) { Initialize(); }
  void AddEdge(const int& from, const int& to, const T& cost);
  T MaxFlow(const int& s, const int& t);

 private:
  struct edge {
    int to;
    T cap;
    int rev;
  };
  int node_size_;
  std::vector<std::vector<edge>> graph_;
  std::vector<int> level;
  std::vector<int> iter;
  void Initialize();
  void BFS(const int& s);
  T DFS(const int& v, const int& t, const int& f);
};

template <typename T>
void Dinic<T>::Initialize() {
  graph_.resize(node_size_);
  level.assign(node_size_, 0);
  iter.assign(node_size_, 0);
}

template <typename T>
void Dinic<T>::AddEdge(const int& from, const int& to, const T& cap) {
  graph_[from].push_back({to, cap, static_cast<int>(graph_[to].size())});
  graph_[to].push_back(
      {from, static_cast<T>(0), static_cast<int>(graph_[from].size()) - 1});
}

template <typename T>
void Dinic<T>::BFS(const int& s) {
  std::fill(level.begin(), level.end(), -1);
  std::queue<int> q;
  level[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    for (const edge& next : graph_[top]) {
      if (next.cap > 0 && level[next.to] < 0) {
        level[next.to] = level[top] + 1;
        q.push(next.to);
      }
    }
  }
}

template <typename T>
T Dinic<T>::DFS(const int& v, const int& t, const int& f) {
  if (v == t) return f;
  for (int& i = iter[v]; i < graph_[v].size(); ++i) {
    edge& e = graph_[v][i];
    if (e.cap > 0 && level[v] < level[e.to]) {
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

template <typename T>
T Dinic<T>::MaxFlow(const int& s, const int& t) {
  T flow = 0;
  for (;;) {
    BFS(s);
    if (level[t] < 0) return flow;
    std::fill(iter.begin(), iter.end(), 0);
    T f;
    while ((f = DFS(s, t, std::numeric_limits<T>::max() / 2)) > 0) {
      flow += f;
    }
  }
}

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