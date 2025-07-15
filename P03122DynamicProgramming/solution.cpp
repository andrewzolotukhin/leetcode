class Solution {
private:
  int cnt[1000][10] = {}, dp[1000][10] = {};
  int solve(int c, int p, int m) {
    if (c == m)
      return 0;
    if (dp[c][p] == 0) {
      for (int i = 0; i < 10; i++) {
        if (c == 0 || i != p) {
          dp[c][p] = max(dp[c][p], cnt[c][i] + solve(c + 1, i, m));
        }
      }
    }
    return dp[c][p];
  }

public:
  int minimumOperations(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cnt[j][grid[i][j]]++;
      }
    }

    return m * n - solve(0, 0, n);
  }
};
