// Union Find Tree(size)
// verified by
//     https://atcoder.jp/contests/abc120/tasks/abc120_d

#include <vector>
#include <cassert>

class UnionFind {
 public:
  UnionFind(int n) : n_(n) { initialize(); }

  int root(int x) {
    assert(0 <= x && x < n_);
    if (parent_[x] < 0)
      return x;
    else
      return parent_[x] = root(parent_[x]);
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
    if (parent_[x] > parent_[y]) std::swap(x, y);
    parent_[x] += parent_[y];
    parent_[y] = x;
    return;
  }

  int size(int x) {
    assert(0 <= x && x < n_);
    return -parent_[root(x)];
  }

 private:
  const int n_;
  std::vector<int> parent_;

  void initialize() { parent_.assign(n_, -1); }
};

// verification code
/*
void ABC120_D() {
  int n, m;
  cin >> n >> m;
  int64 ans = int64{n} * int64{n - 1} / 2;

  UnionFind uf(n);

  vector<pair<int, int>> in;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    in.emplace_back(a, b);
  }

  reverse(in.begin(), in.end());

  vector<int64> v;

  v.emplace_back(ans);

  for (int i = 0; i < m; ++i) {
    if (uf.same(in[i].first, in[i].second)) {
      ;
    } else {
      ans -= uf.size(in[i].first) * uf.size(in[i].second);
      uf.unite(in[i].first, in[i].second);
    }
    v.emplace_back(ans);
  }

  reverse(v.begin(), v.end());

  for (int i = 1; i < m + 1; ++i) {
    cout << v[i] << '\n';
  }
}
*/