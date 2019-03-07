/*
 *  Union-Find(rank)
**/ 

struct UnionFind {
  vector<int> par, rank;

  UnionFind(int n) : par(n , -1), rank(n, 0) {}
  void init(int n) {par.assign(n, -1), rank.assign(n, 0);}

  int root(int x) {
    if (par[x] == -1) return x;
    else return par[x] = root(par[x]);
  }

  bool issame(int x, int y) {return root(x) == root(y);}

  void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return ;
    if (rank[x] < rank[y]) swap(x, y);
    if (rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    return ;
  }
};