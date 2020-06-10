// Dijkstra algorithm
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A

#include <limits>
#include <queue>
#include <vector>

template <class T>
using binary_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

// snippet-begin
template <class _Tp>
class Dijkstra {
 public:
  static constexpr _Tp kInfinity =
      std::numeric_limits<_Tp>::max() / static_cast<_Tp>(2);

  Dijkstra(int node_size) : node_size_(node_size), graph_(node_size) {}

  void add(int from, int to, _Tp cost) {
    assert(0 <= from && from < node_size_ && 0 <= to && to < node_size_);
    graph_[from].emplace_back((edge){to, cost});
  }

  void solve(int source) {
    assert(0 <= source && source < node_size_);
    distance_.assign(node_size_, kInfinity);
    binary_heap<std::pair<_Tp, int>> pq;
    distance_[source] = 0;
    pq.emplace(0, source);

    while (!pq.empty()) {
      std::pair<_Tp, int> cur = pq.top();
      pq.pop();
      int v = cur.second;
      if (distance_[v] < cur.first) continue;
      for (const edge& e : graph_[v]) {
        if (distance_[e.to] > distance_[v] + e.cost) {
          distance_[e.to] = distance_[v] + e.cost;
          pq.emplace(distance_[e.to], e.to);
        }
      }
    }
  }

  _Tp operator[](int to) const {
    assert(0 <= to && to < node_size_);
    return distance_[to];
  }

 private:
  struct edge {
    int to;
    _Tp cost;
  };
  int node_size_;
  std::vector<_Tp> distance_;
  std::vector<std::vector<edge>> graph_;
};
// snippet-end

// verification code
/*
void GRL_1_A() {
  int n, m, r;
  cin >> n >> m >> r;

  Dijkstra<int64> dijkstra(n);

  for (int i = 0; i < m; ++i) {
    int s, t, d;
    cin >> s >> t >> d;
    dijkstra.add(s, t, d);
  }

  dijkstra.solve(r);

  for (int i = 0; i < n; ++i) {
    if (dijkstra[i] == dijkstra.kInfinity) {
      cout << "INF" << '\n';
    } else {
      cout << dijkstra[i] << '\n';
    }
  }
}
*/