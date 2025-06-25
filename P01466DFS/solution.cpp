class Solution {
public:
  int minReorder(int n, vector<vector<int>> &connections) {
    vector<vector<pair<bool, int>>> adj(n, vector<pair<bool, int>>());
    for (auto c : connections) {
      adj[c[0]].push_back({true, c[1]});
      adj[c[1]].push_back({false, c[0]});
    }

    int ans = 0;

    queue<int> q;
    q.push(0);

    vector<bool> visited(n, false);
    visited[0] = true;

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (auto [dir, v] : adj[curr]) {
        if (visited[v])
          continue;
        if (dir) {
          ans++;
        }
        visited[v] = true;
        q.push(v);
      }
    }

    return ans;
  }
};
