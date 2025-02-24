#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int calculateAlicePath(vector<int> &pathSoFar, int step, int vertex,
                         vector<int> &bobPath, vector<int> &parents,
                         vector<int> &amount) {
    if (vertex == 0) {
      int result = amount[0];

      // cout << "=========\n";
      // cout << "0 " << result << endl;

      for (int step = 0; step < pathSoFar.size(); step++) {
        int aliceVertex = pathSoFar[pathSoFar.size() - 1 - step];

        if (bobPath[aliceVertex] != -1 && bobPath[aliceVertex] <= step) {
          // cout << aliceVertex << " 0" << endl;
          continue;
        }
        if (bobPath[aliceVertex] != -1 && bobPath[aliceVertex] == step + 1) {
          result += amount[aliceVertex] / 2;
          // cout << aliceVertex << " " << amount[aliceVertex] / 2 << endl;
        } else {
          result += amount[aliceVertex];
          // cout << aliceVertex << " " << amount[aliceVertex] << endl;
        }
      }

      return result;
    }

    pathSoFar.push_back(vertex);
    return calculateAlicePath(pathSoFar, step + 1, parents[vertex], bobPath,
                              parents, amount);
  }
  void dfs(int n, int parent, int node, set<pair<int, int>> &adj,
           vector<int> &parents, vector<bool> &isLeaf) {
    if (parents[node] != -1)
      return;

    parents[node] = parent;

    for (int i = 0; i < n; i++) {
      if (i != node && adj.count({node, i}) && i != parent &&
          parents[i] == -1) {
        isLeaf[node] = false;
        dfs(n, node, i, adj, parents, isLeaf);
      }
    }
  }

public:
  int mostProfitablePath(vector<vector<int>> &edges, int bob,
                         vector<int> &amount) {
    int n = amount.size();

    vector<int> depth(n, -1);
    depth[0] = 0;

    set<pair<int, int>> adj;
    vector<int> parents(n, -1);
    vector<bool> isLeaf(n, true);
    isLeaf[0] = amount.size() == 1;

    for (int i = 0; i < edges.size(); i++) {
      adj.insert({edges[i][0], edges[i][1]});
      adj.insert({edges[i][1], edges[i][0]});
    }

    for (int i = 1; i < n; i++) {
      if (parents[i] == -1 && adj.count({0, i})) {
        dfs(n, 0, i, adj, parents, isLeaf);
      }
    }

    // edge, gain
    vector<int> bobPath(n, -1);
    int bobPathLen = 0;

    while (bob >= 0) {
      bobPath[bob] = bobPathLen++;
      bob = parents[bob];
    }

    int result = INT_MIN;

    for (int i = 1; i < n; i++) {
      if (!isLeaf[i]) {
        continue;
      }

      vector<int> pathSoFar;
      result = max(result, calculateAlicePath(pathSoFar, 0, i, bobPath, parents,
                                              amount));
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, edgesCount, bob;
  cin >> n >> edgesCount >> bob;

  vector<vector<int>> edges(edgesCount, vector<int>(2));

  for (int i = 0; i < edgesCount; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  vector<int> amount(n);

  for (int i = 0; i < n; i++) {
    cin >> amount[i];
  }

  cout << Solution().mostProfitablePath(edges, bob, amount) << endl;
}
