/**
 *  dijkstra
**/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_V = 1e5;
const int64_t INF = 1e18;

struct edge {
  int64_t to, cost;
};

int n;
vector<edge> G[MAX_V];
int64_t dis[MAX_V];

void dijkstra(int s){
  priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> pq;
  fill(dis, dis + n, INF);
  dis[s] = 0;
  pq.push(pair<int64_t, int64_t>(0, s));

  while (!pq.empty()){
    pair<int64_t, int64_t> p = pq.top(); pq.pop();
    int v = p.second;
    if (dis[v] < p.first) continue;
    for (int i = 0; i < (int) G[v].size(); ++i){
      edge e = G[v][i];
      if (dis[e.to] > dis[v] + e.cost){
        dis[e.to] = dis[v] + e.cost;
        pq.push(pair<int64_t, int64_t>(dis[e.to], e.to));
      }
    }
  }
}

/*
for (int i = 0; i < E; ++i){
  int64_t a, b, c; cin >> a >> b >> c; --a; --b;
  G[a].push_back({b, c});
  G[b].push_back({a, c});
}
*/