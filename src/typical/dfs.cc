// lambda dfs on graph

#include <vector>

std::vector<std::vector<int>> graph(202020);

auto dfs = [&](const auto& dfs, int cur, int prev) -> void {
  for (int next : graph[cur]) {
    if (next == prev) continue;

    // do something

    dfs(dfs, next, cur);
  }
};

/*
dfs(dfs, 0, -1);
*/