// Union Find Tree(weighted)
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B

#include <vector>

class UnionFind {
 public:
  UnionFind(int n, int SUM_UNITY = 0) : n_(n), SUM_UNITY_(SUM_UNITY) {
    Initialize();
  }

  int GetRoot(int x) {
    if (parent_[x] == -1) {
      return x;
    } else {
      int r = GetRoot(parent_[x]);
      diff_weight_[x] += diff_weight_[parent_[x]];
      return parent_[x] = r;
    }
  }

  int Weight(int x) {
    GetRoot(x);
    return diff_weight_[x];
  }

  bool IsSame(int x, int y) { return GetRoot(x) == GetRoot(y); }

  // y is w larger than x
  void Unite(int x, int y, int w) {
    w += Weight(x);
    w -= Weight(y);
    x = GetRoot(x);
    y = GetRoot(y);
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

  int Diff(int x, int y) { return Weight(y) - Weight(x); }

 private:
  const int n_;
  const int SUM_UNITY_;
  std::vector<int> parent_;
  std::vector<int> rank_;
  std::vector<int> diff_weight_;

  void Initialize() {
    parent_.assign(n_, -1);
    rank_.assign(n_, 0);
    diff_weight_.assign(n_, SUM_UNITY_);
  }
};

// verification code
/*
void DSL_1_B() {
  int n, q; cin >> n >> q;
  UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int com; cin >> com;
    if (com == 0) {
      int x, y, z; cin >> x >> y >> z;
      uf.Unite(x, y, z);
    } else {
      int x, y; cin >> x >> y;
      if (!uf.IsSame(x, y)) {
        cout << '?' << '\n';
      } else {
        cout << uf.Diff(x, y) << '\n';
      }
    }
  }
}
*/