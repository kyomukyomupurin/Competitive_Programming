/*
 *  Union-Find(rank)
**/

#include <vector>

struct UnionFind {
  std::vector<int> par, rank;

  UnionFind(int n) : par(n , -1), rank(n, 0) {}

  void init(int n) {
    par.assign(n, -1); rank.assign(n, 0);
  }

  int root(int x) {
    if (par[x] == -1) return x;
    else return par[x] = root(par[x]);
  }

  bool issame(int x, int y) {return root(x) == root(y);}

  void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) std::swap(x, y);
    if (rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    return;
  }
};

// verified by https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A
class UnionFind {
 public:
  UnionFind(int n) : n_(n) {}
  void Initialize();
  int GetRoot(int x);
  bool IsSame(int x, int y);
  void Unite(int x, int y);

 private:
  const int n_;
  std::vector<int> parent_;
  std::vector<int> rank_;
};

void UnionFind::Initialize() {
  parent_.assign(n_, -1);
  rank_.assign(n_, 0);
}

int UnionFind::GetRoot(int x) {
  if (parent_[x] == -1) return x;
  else return parent_[x] = GetRoot(parent_[x]);
}

bool UnionFind::IsSame(int x, int y) {
  return GetRoot(x) == GetRoot(y);
}

void UnionFind::Unite(int x, int y) {
  x = GetRoot(x); y = GetRoot(y);
  if (x == y) return;
  if (rank_[x] < rank_[y]) std::swap(x, y);
  if (rank_[x] == rank_[y]) ++rank_[x];
  parent_[y] = x;
  return;
}