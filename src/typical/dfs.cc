// lambda dfs on graph

#include <vector>

std::vector<std::vector<int>> graph(202020);

auto dfs = [&](auto&& self, int cur, int pre) -> void {
  for (int next : graph[cur]) {
    if (next == pre) continue;

    // do something

    self(self, next, cur);
  }
};

/*
dfs(dfs, 0, -1);
*/