/**
 *  diameter of undirected tree
**/

#include <vector>

// verified by https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
template <typename T>
class TreeDiameter {
 public:
  TreeDiameter(const int& node_size) : node_size_(node_size) { Initialize(); }
  void AddEdge(const int& from, const int& to, const T& cost);
  T GetDiameter();

 private:
  struct edge {
    T cost;
    int to;
  };
  int node_size_;
  std::vector<std::vector<edge>> graph_;
  void Initialize();
  std::pair<T, int> BFS(const int& source);
};

template <typename T>
void TreeDiameter<T>::Initialize() {
  graph_.resize(node_size_);
}

template <typename T>
void TreeDiameter<T>::AddEdge(const int& from, const int& to, const T& cost) {
  graph_[from].push_back({cost, to});
  graph_[to].push_back({cost, from});
}

template <typename T>
T TreeDiameter<T>::GetDiameter() {
  return BFS(BFS(0).second).first;
}

template <typename T>
std::pair<T, int> TreeDiameter<T>::BFS(const int& source) {
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