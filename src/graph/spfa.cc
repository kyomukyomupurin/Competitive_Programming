// Shortest Path Faster Algorithm(SPFA)
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B

#include <limits>
#include <queue>
#include <vector>
// snippet-begin
template <class _Tp>
class SPFA {
 public:
  static constexpr _Tp kInfinity =
      std::numeric_limits<_Tp>::max() / static_cast<_Tp>(2);

  SPFA(int node_size) : node_size_(node_size) { initialize(); }

  void add(int from, int to, _Tp cost) {
    assert(0 <= from && from < node_size_ && 0 <= to && to < node_size_);
    graph_[from].emplace_back((edge){to, cost});
  }

  // use after solve()
  bool find_negative_cycle() const noexcept { return distance_.empty(); }

  void solve(int source) {
    assert(0 <= source && source < node_size_);
    std::queue<int> que;
    que.emplace(source);
    pending_[source] = true;
    ++times_[source];
    distance_[source] = 0;
    while (!que.empty()) {
      int cur = que.front();
      que.pop();
      pending_[cur] = false;
      for (const auto& next : graph_[cur]) {
        _Tp next_cost = distance_[cur] + next.cost;
        if (next_cost >= distance_[next.to]) continue;
        distance_[next.to] = next_cost;
        if (!pending_[next.to]) {
          if (++times_[next.to] >= node_size_) {
            distance_.clear();
            return;
          }
          pending_[next.to] = true;
          que.emplace(next.to);
        }
      }
    }
    return;
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
  std::vector<std::vector<edge>> graph_;
  std::vector<_Tp> distance_;
  std::vector<int> pending_;
  std::vector<int> times_;

  void initialize() {
    graph_.resize(node_size_);
    distance_.assign(node_size_,
                     std::numeric_limits<_Tp>::max() / static_cast<_Tp>(2));
    pending_.assign(node_size_, 0);
    times_.assign(node_size_, 0);
  }
};
// snippet-end

// verification code
/*
void GRL_1_B() {
  int n, m, r;
  cin >> n >> m >> r;
  SPFA<int> spfa(n);
  for (int i = 0; i < m; ++i) {
    int s, t, d;
    cin >> s >> t >> d;
    spfa.add(s, t, d);
  }

  spfa.solve(r);

  if (spfa.find_negative_cycle()) {
    cout << "NEGATIVE CYCLE" << '\n';
  } else {
    for (int i = 0; i < n; ++i) {
      if (spfa[i] == spfa.kInfinity) {
        cout << "INF" << '\n';
      } else {
        cout << spfa[i] << '\n';
      }
    }
  }
}
*/