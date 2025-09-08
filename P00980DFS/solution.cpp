class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ans = 0, n = grid.size(), m = grid[0].size();

    auto isInside = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    int startX = -1, startY = -1;
    int endX = -1, endY = -1, totalFree = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0) {
          totalFree++;
        }
        if (grid[i][j] == 1) {
          startX = i;
          startY = j;
        }
        if (grid[i][j] == 2) {
          endX = i;
          endY = j;
        }
      }
    }

    function<void(int, int, int)> solve = [&](int x, int y, int rem) {
      if (x == endX && y == endY && rem == 0) {
        ans++;
        return;
      }
      grid[x][y] = -1;
      for (int i = 0; i < dirs.size(); i++) {
        int nx = x + dirs[i].first;
        int ny = y + dirs[i].second;

        if (isInside(nx, ny) && grid[nx][ny] != -1) {
          solve(nx, ny, rem - 1);
        }
      }
      grid[x][y] = 0;
    };

    grid[startX][startY] = 0;
    solve(startX, startY, totalFree + 1);

    return ans;
  }
};
