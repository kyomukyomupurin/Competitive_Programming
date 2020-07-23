// Bellman Ford algorithm
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses_/library/5/GRL/1/GRL_1_B

#include <limits>
#include <vector>

// snippet-begin
template <class _Tp>
class BellmanFord {
 public:
  static constexpr _Tp kInfinity =
      std::numeric_limits<_Tp>::max() / static_cast<_Tp>(2);

  BellmanFord(int node_size) : node_size_(node_size) { init(); }

  void add(int from, int to, _Tp cost) {
    assert(0 <= from && from < node_size_ && 0 <= to && to < node_size_);
    es_.emplace_back((edge){from, to, cost});
  }

  // use after bf.solve(source)
  bool find_negative_cycle() const {
    for (const edge& e : es_) {
      if (distance_[e.from] == kInfinity) continue;
      if (distance_[e.from] + e.cost < distance_[e.to]) return true;
    }
    return false;
  }

  void solve(int source) {
    assert(0 <= source && source < node_size_);
    distance_[source] = 0;
    for (int i = 0; i < node_size_ - 1; ++i) {
      for (const edge& e : es_) {
        if (distance_[e.from] == kInfinity) continue;
        if (distance_[e.to] > distance_[e.from] + e.cost) {
          distance_[e.to] = distance_[e.from] + e.cost;
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
    int from, to;
    _Tp cost;
  };
  int node_size_;
  std::vector<_Tp> distance_;
  std::vector<edge> es_;

  void init() { distance_.assign(node_size_, kInfinity); }
};
// snippet-end

// verification code
/*
void GRL_1_B() {
  int n, m, r;
  cin >> n >> m >> r;
  BellmanFord<int> bf(n);
  for (int i = 0; i < m; ++i) {
    int s, t, d;
    cin >> s >> t >> d;
    bf.add(s, t, d);
  }

  bf.solve(r);

  if (bf.find_negative_cycle()) {
    cout << "NEGATIVE CYCLE" << '\n';
  } else {
    for (int i = 0; i < n; ++i) {
      if (bf[i] == bf.kInfinity) {
        cout << "INF" << '\n';
      } else {
        cout << bf[i] << '\n';
      }
    }
  }
}
*/