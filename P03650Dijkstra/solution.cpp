class Solution {
public:
  int minCost(int n, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> adj(n);

    for (auto &edge : edges) {
      adj[edge[0]].push_back({edge[1], edge[2]});
      adj[edge[1]].push_back({edge[0], 2 * edge[2]});
    }

    vector<int> dist(n, INT_MAX);
    vector<bool> v(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        queue;

    dist[0] = 0;
    queue.push({0, 0});

    while (!queue.empty()) {
      int x = queue.top().second;
      queue.pop();

      if (x == n - 1) {
        return dist[x];
      }

      if (v[x])
        continue;

      v[x] = true;

      for (auto &[y, w] : adj[x]) {
        if (dist[x] + w < dist[y]) {
          dist[y] = dist[x] + w;
          queue.push({dist[y], y});
        }
      }
    }
    return -1;
  }
};
