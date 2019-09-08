/**
 *  Union-Find(size)
**/

#include <vector>

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

void UnionFind::Initialize() { parent_.assign(n_, -1); }

int UnionFind::GetRoot(int x) {
  if (parent_[x] < 0)
    return x;
  else
    return parent_[x] = GetRoot(parent_[x]);
}

bool UnionFind::IsSame(int x, int y) { return GetRoot(x) == GetRoot(y); }

void UnionFind::Unite(int x, int y) {
  x = GetRoot(x);
  y = GetRoot(y);
  if (x == y) return;
  if (parent_[x] > parent_[y]) std::swap(x, y);
  parent_[x] += parent_[y];
  parent_[y] = x;
  return;
}

int UnionFind::GetSize(int x) { return -parent_[GetRoot(x)]; }