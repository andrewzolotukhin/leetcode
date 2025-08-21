class Solution {
public:
  int dfs(vector<vector<int>> &grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
      return 0;
    vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int curr = grid[x][y];
    grid[x][y] = 0;
    int ans = curr;

    for (auto dir : dirs) {
      int nx = x + dir.first;
      int ny = y + dir.second;
      ans = max(ans, curr + dfs(grid, nx, ny));
    }

    grid[x][y] = curr;
    return ans;
  }
  int getMaximumGold(vector<vector<int>> &grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j])
          ans = max(ans, dfs(grid, i, j));
      }
    }
    return ans;
  }
};
