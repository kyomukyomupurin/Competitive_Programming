// Union Find Tree(rank)
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A

#include <vector>
#include <cassert>

class UnionFind {
 public:
  UnionFind(int n) : n_(n) { initialize(); }

  int root(int x) {
    assert(0 <= x && x < n_);
    if (par_[x] == -1)
      return x;
    else
      return par_[x] = root(par_[x]);
  }

  bool same(int x, int y) {
    assert(0 <= x && x < n_ && 0 <= y && y < n_);
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    assert(0 <= x && x < n_ && 0 <= y && y < n_);
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (rank_[x] < rank_[y]) std::swap(x, y);
    if (rank_[x] == rank_[y]) ++rank_[x];
    par_[y] = x;
    return;
  }

 private:
  const int n_;
  std::vector<int> par_;
  std::vector<int> rank_;

  void initialize() {
    par_.assign(n_, -1);
    rank_.assign(n_, 0);
  }
};

// verification code
/*
void DSL_1_A() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      uf.unite(x, y);
    } else {
      cout << uf.same(x, y) << '\n';
    }
  }
}
*/