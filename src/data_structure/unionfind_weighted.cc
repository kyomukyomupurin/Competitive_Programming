// Union Find Tree(weighted)
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B

#include <vector>
#include <cassert>

class UnionFind {
 public:
  UnionFind(int n, int SUM_UNITY = 0) : n_(n), SUM_UNITY_(SUM_UNITY) {
    initialize();
  }

  int root(int x) {
    assert(0 <= x && x < n_);
    if (parent_[x] == -1) {
      return x;
    } else {
      int r = root(parent_[x]);
      diff_weight_[x] += diff_weight_[parent_[x]];
      return parent_[x] = r;
    }
  }

  int weight(int x) {
    assert(0 <= x && x < n_);
    root(x);
    return diff_weight_[x];
  }

  bool same(int x, int y) {
    assert(0 <= x && x < n_ && 0 <= y && y < n_);
    return root(x) == root(y);
  }

  // y is w larger than x
  void unite(int x, int y, int w) {
    assert(0 <= x && x < n_ && 0 <= y && y < n_);
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (rank_[x] < rank_[y]) {
      std::swap(x, y);
      w = -w;
    }
    if (rank_[x] == rank_[y]) ++rank_[x];
    parent_[y] = x;
    diff_weight_[y] = w;
    return;
  }

  int diff(int x, int y) {
    assert(0 <= x && x < n_ && 0 <= y && y < n_);
    return weight(y) - weight(x);
  }

 private:
  const int n_;
  const int SUM_UNITY_;
  std::vector<int> parent_;
  std::vector<int> rank_;
  std::vector<int> diff_weight_;

  void initialize() {
    parent_.assign(n_, -1);
    rank_.assign(n_, 0);
    diff_weight_.assign(n_, SUM_UNITY_);
  }
};

// verification code
/*
void DSL_1_B() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int com;
    cin >> com;
    if (com == 0) {
      int x, y, z;
      cin >> x >> y >> z;
      uf.unite(x, y, z);
    } else {
      int x, y;
      cin >> x >> y;
      if (!uf.same(x, y)) {
        cout << '?' << '\n';
      } else {
        cout << uf.diff(x, y) << '\n';
      }
    }
  }
}
*/