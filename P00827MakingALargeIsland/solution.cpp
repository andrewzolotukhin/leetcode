#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
private:
  bool isInside(int n, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
  }
  int getIslandSize(int x, int y, int index, vector<vector<int>> &visited,
                    vector<vector<int>> &grid, set<pair<int, int>> &zeroes) {
    int n = visited.size();
    int result = 1;
    visited[x][y] = index;

    queue<pair<int, int>> q;

    q.push({x, y});

    while (!q.empty()) {
      auto [cx, cy] = q.front();
      q.pop();

      for (int i = 0; i < directions.size(); i++) {
        int newX = cx + directions[i].first;
        int newY = cy + directions[i].second;

        if (isInside(n, newX, newY)) {
          if (grid[newX][newY] == 0) {
            zeroes.insert({newX, newY});
            continue;
          }
          if (grid[newX][newY] != 0 && visited[newX][newY] == -1) {
            visited[newX][newY] = index;
            result++;
            q.push({newX, newY});
          }
        }
      }
    }

    return result;
  }

public:
  int largestIsland(vector<vector<int>> &grid) {
    int n = grid.size();
    set<pair<int, int>> zeroes;
    vector<vector<int>> visited(n, vector<int>(n, -1));

    vector<int> islands;
    int totalIslands = 0;
    int maxIsland = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          continue;
        }
        if (visited[i][j] != -1)
          continue;

        islands.push_back(
            getIslandSize(i, j, totalIslands, visited, grid, zeroes));
        maxIsland = max(maxIsland, islands[totalIslands]);
        totalIslands++;
      }
    }

    int result = maxIsland;
    for (auto [x, y] : zeroes) {
      set<int> usedIslands;
      for (int j = 0; j < directions.size(); j++) {
        int newX = x + directions[j].first;
        int newY = y + directions[j].second;
        if (isInside(n, newX, newY) && visited[newX][newY] != -1) {
          usedIslands.insert(visited[newX][newY]);
        }
      }

      int cr = 1;
      for (auto id : usedIslands) {
        cr += islands[id];
      }

      result = max(result, cr);
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;

  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  cout << Solution().largestIsland(grid) << '\n';
}
