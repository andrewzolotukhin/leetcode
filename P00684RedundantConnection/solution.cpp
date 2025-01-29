#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = -1;
    for (int i = 0; i < edges.size(); i++) {
      n = max(max(n, edges[i][0]), edges[i][1]);
    }

    vector<set<int>> adj(n, set<int>());

    for (int i = 0; i < edges.size(); i++) {
      adj[edges[i][0] - 1].insert(edges[i][1] - 1);
      adj[edges[i][1] - 1].insert(edges[i][0] - 1);
    }

    vector<int> queue;
    vector<bool> removed(n, false);

    for (int i = 0; i < n; i++) {
      if (adj[i].size() < 2) {
        queue.push_back(i);
      }
    }

    while (!queue.empty()) {
      auto vertex = queue.front();
      queue.erase(queue.begin());

      removed[vertex] = true;

      for (auto c : adj[vertex]) {
        if (removed[c])
          continue;

        adj[c].erase(vertex);
        adj[vertex].erase(c);
        if (adj[c].size() < 2) {
          queue.push_back(c);
        }
      }
    }

    for (int i = edges.size() - 1; i >= 0; i--) {
      if (removed[edges[i][0] - 1] || removed[edges[i][1] - 1])
        continue;

      return edges[i];
    }

    assert(false);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int m;
  cin >> m;

  vector<vector<int>> edges(m, vector<int>(2));

  for (int i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  auto result = Solution().findRedundantConnection(edges);

  cout << result[0] << " " << result[1] << endl;
}
