#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool biparite(int u, int p, vector<int> &part, vector<vector<bool>> &adj) {
    part[u] = p;

    for (int v = 0; v < adj[u].size(); v++) {
      if (!adj[u][v])
        continue;
      if (part[v] == part[u])
        return false;

      if (part[v] == -1) {
        if (!biparite(v, 1 - p, part, adj)) {
          return false;
        }
      } else {
        continue;
      }
    }

    return true;
  }

  int dfs(int vertex, vector<vector<bool>> &adj, int n) {
    vector<bool> visited(n, false);
    queue<int> queue;
    queue.push(vertex);
    visited[vertex] = true;

    int result = 0;

    while (!queue.empty()) {
      int currentSize = queue.size();
      for (int i = 0; i < currentSize; i++) {
        int current = queue.front();
        queue.pop();

        visited[current] = true;

        for (int j = 0; j < adj[current].size(); j++) {
          if (current == j)
            continue;
          if (!adj[current][j])
            continue;
          if (visited[j])
            continue;
          visited[j] = true;
          queue.push(j);
        }
      }
      result++;
    }

    return result;
  }

  // Calculates the maximum number of groups for a connected component
  int getNumberOfGroupsForComponent(vector<vector<bool>> &adjList, int node,
                                    vector<int> &distances,
                                    vector<bool> &visited) {
    // Start with the distance of the current node as the maximum
    int maxNumberOfGroups = distances[node];
    visited[node] = true;

    // Recursively calculate the maximum for all unvisited neighbors
    for (int neighbor = 0; neighbor < adjList[node].size(); neighbor++) {
      if (!adjList[node][neighbor])
        continue;
      if (visited[neighbor])
        continue;
      maxNumberOfGroups = max(
          maxNumberOfGroups,
          getNumberOfGroupsForComponent(adjList, neighbor, distances, visited));
    }
    return maxNumberOfGroups;
  }

public:
  int magnificentSets(int n, vector<vector<int>> &edges) {
    // first check that edges are biparite
    vector<int> part(n, -1);
    vector<vector<bool>> adj(n, vector<bool>(n, false));

    for (int i = 0; i < edges.size(); i++) {
      adj[edges[i][0] - 1][edges[i][1] - 1] = true;
      adj[edges[i][1] - 1][edges[i][0] - 1] = true;
    }

    for (int i = 0; i < n; i++) {
      if (part[i] != -1)
        continue;

      if (!biparite(i, 0, part, adj)) {
        return -1;
      }
    }

    int result = 0;
    vector<int> distances(n, 0);

    for (int i = 0; i < n; i++) {
      distances[i] = dfs(i, adj, n);
    }

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
      if (visited[i])
        continue;

      result += getNumberOfGroupsForComponent(adj, i, distances, visited);
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> edges(m, vector<int>(2));

  for (int i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  cout << Solution().magnificentSets(n, edges) << '\n';
}
