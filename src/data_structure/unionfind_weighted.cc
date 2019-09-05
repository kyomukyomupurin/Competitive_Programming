/**
 *  Union-Find(weighted)
**/

#include <vector>

// verified by https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
class UnionFind {
 public:
  UnionFind(int n, int SUM_UNITY = 0) : n_(n), 
                                        SUM_UNITY_(SUM_UNITY) {}
  void Initialize();
  int GetRoot(int x);
  int Weight(int x);
  bool IsSame(int x, int y);
  void Unite(int x, int y, int w);
  int Diff(int x, int y);

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

void UnionFind::Unite(int x, int y, int w) {  // y is w larger than x
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

int UnionFind::Diff(int x, int y) {
  return Weight(y) - Weight(x);
}