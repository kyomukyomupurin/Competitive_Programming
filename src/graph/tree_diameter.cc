// Diameter of undirected tree
// verified by
//     https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A

#include <algorithm>
#include <vector>

#include "./bfs.cc"
#include "./graph.cc"

// snippet-begin
template <class T>
T tree_diameter(const forest<T>& g) {
  std::vector<T> d1 = bfs(g, 0);
  std::vector<T> d2 = bfs(g, std::distance(d1.begin(), std::max_element(d1.begin(), d1.end())));
  return *std::max_element(d2.begin(), d2.end());
}
// snippet-end

// verification code
/*
void GRL_5_A() {
  int n; cin >> n;
  forest<int> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, d; cin >> s >> t >> d;
    g.add(s, t, d);
  }
  cout << tree_diameter(g) << '\n';
}
*/