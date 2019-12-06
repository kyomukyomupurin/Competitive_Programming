/**
 *  bellman ford
**/

#include <limits>
#include <vector>

// verified by https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
template<typename T>
class BellmanFord {
 public:
  BellmanFord(int node_size) : node_size_(node_size) { Initialize(); }
  void AddEdge(int from, int to, T cost);
  bool ExistNegativeCycle();
  void Solve(int source);
  T operator[](int to) const;

 private:
  struct edge {
    int from, to;
    T cost;
  };
  int node_size_;
  std::vector<T> distance_;
  std::vector<edge> es;
  void Initialize();
};

template<typename T>
void BellmanFord<T>::AddEdge(int from, int to, T cost) {
  es.push_back({from, to, cost});
}

// use after bf.solve(source) !
template<typename T>
bool BellmanFord<T>::ExistNegativeCycle() {
  for (const auto &e : es) {
    if (distance_[e.from] == std::numeric_limits<T>::max() / 2) continue;
    if (distance_[e.from] + e.cost < distance_[e.to]) return true;
  }
  return false;
}

template<typename T>
void BellmanFord<T>::Solve(int source) {
  distance_[source] = 0;
  for (int i = 0; i < node_size_ - 1; ++i) {
    for (const auto &e : es) {
      if (distance_[e.from] == std::numeric_limits<T>::max() / 2) continue;
      if (distance_[e.to] > distance_[e.from] + e.cost) {
        distance_[e.to] = distance_[e.from] + e.cost;
      }
    }
  }
}

template<typename T>
void BellmanFord<T>::Initialize() {
  distance_.assign(node_size_, std::numeric_limits<T>::max() / 2);
}

template<typename T>
T BellmanFord<T>::operator[](int to) const {
  return distance_[to];
}

/*
void GRL_1_B() {
  int n, m, r; cin >> n >> m >> r;
  BellmanFord<int> bf(n);
  for (int i = 0; i < m; ++i) {
    int s, t, d; cin >> s >> t >> d;
    bf.AddEdge(s, t, d);
  }

  bf.Solve(r);

  if (bf.ExistNegativeCycle()) {
    cout << "NEGATIVE CYCLE" << '\n';
  } else {
    for (int i = 0; i < n; ++i) {
      if (bf[i] == std::numeric_limits<int>::max() / 2) {
        cout << "INF" << '\n';
      } else {
        cout << bf[i] << '\n';
      }
    }
  }
}
*/