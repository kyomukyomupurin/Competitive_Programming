/**
 *  dijkstra
**/

#include <iostream>
#include <queue>
#include <vector>
using int64 = long long;

const int MAX_V = 101010;
const int64 INF64 = (1LL<<62) - 1;

struct edge {
  int64 to, cost;
};

int n;
std::vector<edge> G[MAX_V];
int64 dis[MAX_V];

void dijkstra(int s){
  std::priority_queue<std::pair<int64, int64>,
                      std::vector<std::pair<int64, int64>>,
                      std::greater<std::pair<int64, int64>>> pq;
  std::fill(dis, dis + n, INF64);
  dis[s] = 0;
  pq.push(std::pair<int64, int64>(0, s));

  while (!pq.empty()){
    std::pair<int64, int64> p = pq.top(); pq.pop();
    int v = p.second;
    if (dis[v] < p.first) continue;
    for (size_t i = 0; i < G[v].size(); ++i){
      edge e = G[v][i];
      if (dis[e.to] > dis[v] + e.cost){
        dis[e.to] = dis[v] + e.cost;
        pq.emplace(std::pair<int64, int64>(dis[e.to], e.to));
      }
    }
  }
}

/*
for (int i = 0; i < E; ++i){
  int64 a, b, c; cin >> a >> b >> c; --a; --b;
  G[a].push_back({b, c});
  G[b].push_back({a, c});
}
*/