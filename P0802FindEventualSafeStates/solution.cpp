#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> adj(n, vector<int>());
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++) {
      for (auto x : graph[i]) {
        adj[x].push_back(i);
        indegree[i]++;
      }
    }

    vector<int> q;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        q.push_back(i);
      }
    }

    vector<bool> safe(n, false);

    while (!q.empty()) {
      int node = q.front();
      q.erase(q.begin());
      safe[node] = true;

      for (auto x : adj[node]) {
        indegree[x]--;
        if (indegree[x] == 0) {
          q.push_back(x);
        }
      }
    }

    vector<int> result;

    for (int i = 0; i < n; i++) {
      if (safe[i]) {
        result.push_back(i);
      }
    }
    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  vector<vector<int>> graph;

  while (n--) {
    int k;
    cin >> k;

    vector<int> adj;

    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      adj.push_back(x);
    }

    graph.push_back(adj);
  }

  Solution sol;

  auto res = sol.eventualSafeNodes(graph);

  for (auto x : res) {
    cout << x << '\n';
  }
}
