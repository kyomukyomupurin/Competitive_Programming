/**
 *  bellman ford
**/

#include <vector>

template<typename T> inline void chmin(T &a, T b) {if (a > b) a = b; return;}

const int MAX_V = 2020;
const int INF = (1<<30) - 1;

struct edge{
  int from, to, cost;
};

std::vector<edge> es;
std::vector<int> dis(MAX_V, INF);

// if true, there is at least one negative cycle
bool Bellman_Ford(int V, int source) {
  dis[source] = 0;
  for (int i = 0; i < V - 1; ++i) {
    for (auto &e : es) {
      if (dis[e.from] == INF) continue;
      chmin(dis[e.to], dis[e.from] + e.cost);
    }
  }

  // whether there is an update in the Vth loop
  for (auto &e : es) {
    if (dis[e.from] == INF) continue;
    if (dis[e.from] + e.cost < dis[e.to]) return true;
  }
  return false;
}

/*
for (int i = 0; i < E; ++i) {
  int s, t, d; cin >> s >> t >> d;
  es.push_back({s, t, d});
}
*/
