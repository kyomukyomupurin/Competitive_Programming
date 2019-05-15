/**
 *  Union-Find(size)
**/

#include <iostream>
#include <vector>

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

  int64_t size(int x) {return -par[root(x)];}
};