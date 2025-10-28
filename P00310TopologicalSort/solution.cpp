class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    vector<int> ans;
    if (n == 1)
      return {0};
    if (n == 2)
      return {0, 1};
    int val = INT_MAX;
    vector<vector<int>> adj(n);
    vector<int> degree(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
      degree[e[0]]++;
      degree[e[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (degree[i] == 1)
        q.push(i);
    }

    int remaining = n;
    while (remaining > 2) {
      int sz = q.size();
      remaining -= sz;
      for (int i = 0; i < sz; ++i) {
        int leaf = q.front();
        q.pop();
        for (int nei : adj[leaf]) {
          if (--degree[nei] == 1)
            q.push(nei);
        }
      }
    }

    while (!q.empty()) {
      ans.push_back(q.front());
      q.pop();
    }
    return ans;
  }
};
