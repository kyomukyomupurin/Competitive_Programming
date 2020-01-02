// Union Find Tree(rank)
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A

#include <vector>

class UnionFind {
 public:
  UnionFind(int n) : n_(n) { Initialize(); }

  int GetRoot(int x) {
    if (parent_[x] == -1)
      return x;
    else
      return parent_[x] = GetRoot(parent_[x]);
  }

  bool IsSame(int x, int y) { return GetRoot(x) == GetRoot(y); }

  void Unite(int x, int y) {
    x = GetRoot(x);
    y = GetRoot(y);
    if (x == y) return;
    if (rank_[x] < rank_[y]) std::swap(x, y);
    if (rank_[x] == rank_[y]) ++rank_[x];
    parent_[y] = x;
    return;
  }

 private:
  const int n_;
  std::vector<int> parent_;
  std::vector<int> rank_;

  void Initialize() {
    parent_.assign(n_, -1);
    rank_.assign(n_, 0);
  }
};

// verification code
/*
void DSL_1_A() {
  int n, q; cin >> n >> q;
  UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int com, x, y; cin >> com >> x >> y;
    if (com == 0) {
      uf.Unite(x, y);
    } else {
      cout << uf.IsSame(x, y) << '\n';
    }
  }
}
*/