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

class UnionFind {
 public:
  UnionFind(int n) : n_(n) {}
  void initialize();
  int getroot(int x);
  bool issame(int x, int y);
  void unite(int x, int y);

 private:
  const int n_;
  std::vector<int> parent_;
  std::vector<int> rank_;
};

void UnionFind::initialize() {
  parent_.assign(n_, -1);
  rank_.assign(n_, 0);
}

int UnionFind::getroot(int x) {
  if (parent_[x] == -1) return x;
  else return parent_[x] = getroot(parent_[x]);
}

bool UnionFind::issame(int x, int y) {
  return getroot(x) == getroot(y);
}

void UnionFind::unite(int x, int y) {
  x = getroot(x); y = getroot(y);
  if (x == y) return;
  if (rank_[x] < rank_[y]) std::swap(x, y);
  if (rank_[x] == rank_[y]) ++rank_[x];
  parent_[y] = x;
  return;
}