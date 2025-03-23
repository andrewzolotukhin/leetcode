class Solution {
public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<long long> dist(n, LLONG_MAX);
    dist[0] = 0;
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < roads.size(); i++) {
      int f = roads[i][0];
      int t = roads[i][1];
      int d = roads[i][2];
      graph[f].push_back({t, d});
      graph[t].push_back({f, d});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<>>
        pq;

    pq.push({0, 0});

    int ans = 0;
    vector<int> pathCount(n, 0);
    pathCount[0] = 1;
    int mod = 1e9 + 7;

    while (!pq.empty()) {
      auto d = pq.top().first;
      auto v = pq.top().second;
      pq.pop();

      if (d > dist[v])
        continue;

      for (auto &[neighbor, distance] : graph[v]) {
        if (d + distance < dist[neighbor]) {
          dist[neighbor] = d + distance;
          pathCount[neighbor] = pathCount[v];
          pq.push({dist[neighbor], neighbor});
        } else if (d + distance == dist[neighbor]) {
          pathCount[neighbor] = (pathCount[neighbor] + pathCount[v]) % mod;
        }
      }
    }

    return pathCount[n - 1];
  }
};
