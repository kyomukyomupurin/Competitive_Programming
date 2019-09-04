/**
 *  Union-Find(size)
**/

#include <iostream>
#include <vector>
using int64 = long long;

struct UnionFind {
  std::vector<int> par;

  UnionFind(int n) : par(n, -1) {}
  void init(int n) {par.assign(n, -1);}

  int root(int x) {
    if (par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }

  bool issame(int x, int y) {return root(x) == root(y);}

  void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (par[x] > par[y]) std::swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return;
  }

  int64 size(int x) {return -par[root(x)];}
};

// verified by https://atcoder.jp/contests/abc120/tasks/abc120_d
class UnionFind {
 public:
  UnionFind(int n) : n_(n) {}
  void Initialize();
  int GetRoot(int x);
  bool IsSame(int x, int y);
  void Unite(int x, int y);
  int GetSize(int x);

 private:
  const int n_;
  std::vector<int> parent_;
};

void UnionFind::Initialize() {
  parent_.assign(n_, -1);
}

int UnionFind::GetRoot(int x) {
  if (parent_[x] < 0) return x;
  else return parent_[x] = GetRoot(parent_[x]);
}

bool UnionFind::IsSame(int x, int y) {
  return GetRoot(x) == GetRoot(y);
}

void UnionFind::Unite(int x, int y) {
  x = GetRoot(x); y = GetRoot(y);
  if (x == y) return;
  if (parent_[x] > parent_[y]) std::swap(x, y);
  parent_[x] += parent_[y];
  parent_[y] = x;
  return;
}

int UnionFind::GetSize(int x) {
  return -parent_[GetRoot(x)];
}