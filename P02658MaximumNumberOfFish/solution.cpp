#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMaxFish(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    vector<pair<pair<int, int>, int>> queue;
    int totalWater = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] > 0) {
          queue.push_back({{i, j}, -1});
          totalWater++;
        }
      }
    }

    if (totalWater == 0) {
      return 0;
    }

    vector<int> components;

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    auto isInside = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    int currentC = -2;
    while (!queue.empty()) {
      auto item = queue.back();
      auto [p, c] = item;
      auto [x, y] = p;

      queue.erase(queue.end());

      if (visited[x][y])
        continue;

      if (c != currentC) {
        components.push_back(0);
        currentC = components.size() - 1;
      }

      components[currentC] += grid[x][y];
      visited[x][y] = true;

      for (int i = 0; i < directions.size(); i++) {
        int newX = x + directions[i].first;
        int newY = y + directions[i].second;

        if (isInside(newX, newY) && !visited[newX][newY] &&
            grid[newX][newY] > 0) {
          pair<pair<int, int>, int>(pair<int, int>(newX, newY), currentC);
          queue.push_back({{newX, newY}, currentC});
        }
      }
    }

    int result = -1;
    for (int i = 0; i < components.size(); i++) {
      result = max(result, components[i]);
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  cout << Solution().findMaxFish(grid) << endl;
}
