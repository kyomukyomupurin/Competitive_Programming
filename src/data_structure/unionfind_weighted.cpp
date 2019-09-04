/**
 *  Union-Find(weighted)
**/

#include <vector>

struct UnionFind {
  std::vector<int> par, rank, diff_weight;
 
  UnionFind(int n = 1, int SUM_UNITY = 0) {init(n, SUM_UNITY);}
 
  void init(int n = 1, int SUM_UNITY = 0) {
    par.resize(n); rank.resize(n); diff_weight.resize(n);
    for (int i = 0; i < n; ++i) {
      par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }
  }
 
  int root(int x) {
    if (par[x] == x) return x;
    else {
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }
 
  int weight(int x) {root(x); return diff_weight[x];}
 
  bool issame(int x, int y) {return root(x) == root(y);}
 
  void unite(int x, int y, int w) {
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) std::swap(x, y), w = -w;
    if (rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return;
  }
 
  int diff(int x, int y) {return weight(y) - weight(x);}
};

class UnionFind {
 public:
  UnionFind(int n, int SUM_UNITY = 0) : n_(n), 
                                        SUM_UNITY_(SUM_UNITY) {}
  void Initialize();
  int GetRoot(int x);
  int Weight(int x);
  bool IsSame(int x, int y);
  void Unite(int x, int y, int w);

 private:
  const int n_;
  const int SUM_UNITY_;
  std::vector<int> parent_;
  std::vector<int> rank_;
  std::vector<int> diff_weight_;
};

void UnionFind::Initialize() {
  parent_.assign(n_, -1);
  rank_.assign(n_, 0);
  diff_weight_.assign(n_, SUM_UNITY_);
}

int UnionFind::GetRoot(int x) {
  if (parent_[x] == -1) {
    return x;
  } else {
    int r = GetRoot(parent_[x]);
    diff_weight_[x] += diff_weight_[parent_[x]];
    return parent_[x] = r;
  }
}

int UnionFind::Weight(int x) {
  GetRoot(x);
  return diff_weight_[x];
}

bool UnionFind::IsSame(int x, int y) {
  return GetRoot(x) == GetRoot(y);
}

// y is w larger than x
void UnionFind::Unite(int x, int y, int w) {
  w += Weight(x); w -= Weight(y);
  x = GetRoot(x); y = GetRoot(y);
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