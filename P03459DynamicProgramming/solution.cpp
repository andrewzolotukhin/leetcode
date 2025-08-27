class Solution {
private:
  vector<pair<int, int>> dirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
  int dfs(vector<vector<int>> &grid, vector<vector<vector<vector<int>>>> &dp,
          int x, int y, int dir, bool notTurned, int expected) {
    int n = grid.size(), m = grid[0].size();
    int nx = x + dirs[dir].first;
    int ny = y + dirs[dir].second;

    if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != expected) {
      return 0;
    }

    if (dp[nx][ny][dir][notTurned] != -1)
      return dp[nx][ny][dir][notTurned];

    int mx = dfs(grid, dp, nx, ny, dir, notTurned, 2 - expected);
    if (notTurned) {
      mx = max(mx, dfs(grid, dp, nx, ny, (dir + 1) % 4, false, 2 - expected));
    }
    return dp[nx][ny][dir][notTurned] = mx + 1;
  }

public:
  int lenOfVDiagonal(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();

    vector<vector<vector<vector<int>>>> dp(
        n, vector<vector<vector<int>>>(
               m, vector<vector<int>>(4, vector<int>(2, -1))));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          for (int d = 0; d <= 3; d++) {
            ans = max(ans, dfs(grid, dp, i, j, d, true, 2) + 1);
          }
        }
      }
    }
    return ans;
  }
};
