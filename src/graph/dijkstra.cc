/**
 *  dijkstra
**/

#include <queue>
#include <vector>
#include <limits>

// verified by https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
template<typename T>
class Dijkstra {
 public:
  Dijkstra(int node_size) : node_size_(node_size) { Initialize(); }
  void Add_Edge(int from, int to, T cost);
  void Solve(int source);
  T operator[](int to) const;

 private:
  struct edge {
   int to;
   T cost;
  };
  int node_size_;
  std::vector<T> distance_;
  std::vector<std::vector<edge>> graph_;
  void Initialize();
};

template<typename T>
void Dijkstra<T>::Add_Edge(int from, int to, T cost) {
  graph_[from].push_back({to, cost});
}

template<typename T>
void Dijkstra<T>::Solve(int source) {
  std::priority_queue<std::pair<T, int>,
                      std::vector<std::pair<T, int>>,
                      std::greater<std::pair<T, int>>> pq;
  distance_[source] = 0;
  pq.push({0, source});

  while (!pq.empty()){
    std::pair<T, int> top = pq.top(); pq.pop();
    int v = top.second;
    if (distance_[v] < top.first) continue;
    for (const auto& e : graph_[v]) {
      if (distance_[e.to] > distance_[v] + e.cost){
        distance_[e.to] = distance_[v] + e.cost;
        pq.push({distance_[e.to], e.to});
      }
    }
  }
}

template<typename T>
void Dijkstra<T>::Initialize() {
  distance_.assign(node_size_, std::numeric_limits<T>::max() / 2);
  graph_.resize(node_size_);
}

template<typename T>
T Dijkstra<T>::operator[](int to) const {
  return distance_[to];
}

/*
void GRL_1_A() {
  int n, m, r; cin >> n >> m >> r;

  Dijkstra<int64> dijkstra(n);

  for (int i = 0; i < m; ++i) {
    int s, t, d; cin >> s >> t >> d;
    dijkstra.Add_Edge(s, t, d);
  }

  dijkstra.Solve(r);

  for (int i = 0; i < n; ++i) {
    if (dijkstra[i] == numeric_limits<int64>::max() / 2) {
      cout << "INF" << '\n';
    } else {
      cout << dijkstra[i] << '\n';
    }
  }
}
*/