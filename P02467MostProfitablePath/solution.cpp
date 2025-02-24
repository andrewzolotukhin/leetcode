#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mostProfitablePath(vector<vector<int>> &edges, int bob,
                         vector<int> &amount) {
    int n = amount.size(), maxIncome = INT_MIN;
    tree.resize(n);
    isVisited.assign(n, false);
    queue<vector<int>> nodeQueue;

    // {sourceNode, time, income}
    nodeQueue.push({0, 0, 0});

    for (vector<int> edge : edges) {
      tree[edge[0]].push_back(edge[1]);
      tree[edge[1]].push_back(edge[0]);
    }

    goBob(bob, 0);

    isVisited.assign(n, false);
    while (!nodeQueue.empty()) {
      int sourceNode = nodeQueue.front()[0], time = nodeQueue.front()[1],
          income = nodeQueue.front()[2];
      nodeQueue.pop();

      if (bobPath.find(sourceNode) == bobPath.end() ||
          time < bobPath[sourceNode]) {
        income += amount[sourceNode];
      }

      else if (time == bobPath[sourceNode]) {
        income += (amount[sourceNode] / 2);
      }

      if (tree[sourceNode].size() == 1 && sourceNode != 0) {
        maxIncome = max(maxIncome, income);
      }
      for (int adjacentNode : tree[sourceNode]) {
        if (!isVisited[adjacentNode]) {
          nodeQueue.push({adjacentNode, time + 1, income});
        }
      }

      isVisited[sourceNode] = true;
    }
    return maxIncome;
  }

private:
  unordered_map<int, int> bobPath;
  vector<bool> isVisited;
  vector<vector<int>> tree;

  bool goBob(int source, int time) {
    bobPath[source] = time;
    isVisited[source] = true;

    if (source == 0) {
      return true;
    }

    for (auto neighbor : tree[source]) {
      if (!isVisited[neighbor]) {
        if (goBob(neighbor, time + 1)) {
          return true;
        }
      }
    }

    bobPath.erase(source);
    return false;
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
