// Random tree(0-indexed, undirected, unweighted) generator

#include <algorithm>
#include <set>
#include <vector>
#include "../competitive_programming/src/data_structure/unionfind_size.cc"
#include "../competitive_programming/src/etc/xorshift.cc"

std::vector<std::pair<int, int>> RandomTree(int node_size) {
  std::vector<std::pair<int, int>> tree;
  std::uniform_int_distribution<int> dist(0, node_size - 1);
  UnionFind uf(node_size);
  Xorshift rng;

  while (uf.GetSize(0) < node_size) {
    int x = dist(rng), y = dist(rng);
    if (x == y || uf.IsSame(x, y)) continue;
    if (x > y) std::swap(x, y);
    uf.Unite(x, y);
    tree.emplace_back(x, y);
  }

  std::sort(tree.begin(), tree.end());

  return tree;
};
