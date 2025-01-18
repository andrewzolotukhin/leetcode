#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
  int minCost(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto isInside = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
    cost[0][0] = 0;

    priority_queue<vector<int>, vector<vector<int>>, greater<>> queue;
    queue.push({0, 0, 0});

    while (!queue.empty()) {
      auto current = queue.top();
      queue.pop();

      int currCost = current[0], x = current[1], y = current[2];

      if (cost[x][y] != currCost)
        continue;

      for (int i = 0; i < dirs.size(); i++) {
        int newX = x + dirs[i].first;
        int newY = y + dirs[i].second;

        if (!isInside(newX, newY))
          continue;

        int newCost = currCost + (((grid[x][y] - 1) != i) ? 1 : 0);

        if (newCost < cost[newX][newY]) {
          cost[newX][newY] = newCost;
          queue.push({newCost, newX, newY});
        }
      }
    }

    return cost[n - 1][m - 1];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>());

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      grid[i].push_back(x);
    }
  }

  Solution s;

  cout << s.minCost(grid) << '\n';
}
