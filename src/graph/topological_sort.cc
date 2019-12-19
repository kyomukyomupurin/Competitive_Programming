/**
 *  Topological Sort
**/

#include <algorithm>
#include <vector>
#include <queue>

// verified by https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
class TopologicalSort {
 public:
  TopologicalSort(int node_size) : node_size_(node_size) { Initialize(); }
  void AddEdge(int from, int to) {
    graph_[from].emplace_back(to);
    ++level_[to];
  }
  void Sort() {
    std::queue<int> que;
    for (int i = 0; i < node_size_; ++i) {
      if (level_[i] == 0) que.push(i);
    }
    while (!que.empty()) {
      int top = que.front();
      que.pop();
      result_.emplace_back(top);
      for (int next : graph_[top]) {
        if (--level_[next] == 0) que.push(next);
      }
    }
  }
  // use after Sort()!
  bool IsDAG() {
    return all_of(level_.begin(), level_.end(), [](int x) { return x == 0; });
  }
  int operator[](int position) const { return result_[position]; }

 private:
  int node_size_;
  std::vector<std::vector<int>> graph_;
  std::vector<int> level_;
  std::vector<int> result_;
  void Initialize() {
    graph_.resize(node_size_);
    level_.assign(node_size_, 0);
  }
};

/*
void GRL_4_B() {
  int n, m; cin >> n >> m;
  TopologicalSort ts(n);
  for (int i = 0; i < m; ++i) {
    int s, t; cin >> s >> t;
    ts.AddEdge(s, t);
  }
  ts.Sort();
  if (ts.IsDAG()) {
    for (int i = 0; i < n; ++i) {
      cout << ts[i] << '\n';
    }
  }
}
*/