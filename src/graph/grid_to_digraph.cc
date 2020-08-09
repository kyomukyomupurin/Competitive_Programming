// helper function to convert grid-graph to digraph

#include <string>
#include <vector>

#include "./graph.cc"

digraph<int> grid_to_digraph(const std::vector<std::string>& sv) {
  int h = sv.size(), w = sv[0].size();
  digraph<int> g(h * w);
  constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
  auto Out = [&](int x, int y) { return (x < 0 || x >= h || y < 0 || y >= w); };
  auto Compress = [&](int x, int y) { return x * w + y; };
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      for (int k = 0; k < 4; ++k) {
        int nx = i + dx[k], ny = j + dy[k];
        if (Out(nx, ny)) continue;
        if (/* edit here */) {
          g.add(Compress(i, j), Compress(nx, ny));
        }
      }
    }
  }
  return g;
}