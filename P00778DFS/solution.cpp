class Solution {
private:
  vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  bool dfs(vector<vector<int>> &grid, int x, int y, int level) {
    int n = grid.size();
    if (grid[x][y] > level)
      return false;
    grid[x][y] = -1;
    if (x == n - 1 && y == n - 1)
      return true;

    for (auto d : dirs) {
      int nx = x + d.first;
      int ny = y + d.second;

      if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == -1)
        continue;
      if (dfs(grid, nx, ny, level)) {
        return true;
      }
    }

    return false;
  }

public:
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size(), l = 0, r = n * n - 1;

    int ans = INT_MAX;
    while (l <= r) {
      int mid = (l + r) / 2;
      vector<vector<int>> g = grid;
      if (dfs(g, 0, 0, mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }
};
