class Solution {
public:
  int maxProductPath(vector<vector<int>> &grid) {
    const int MOD = 1e9 + 7;
    int n = grid.size(), m = grid[0].size();
    vector<vector<long long>> mx(n, vector<long long>(m));
    vector<vector<long long>> mn(n, vector<long long>(m));

    mx[0][0] = mn[0][0] = grid[0][0];
    for (int i = 1; i < n; i++) {
      mx[i][0] = mn[i][0] = mx[i - 1][0] * grid[i][0];
    }

    for (int j = 1; j < m; j++) {
      mx[0][j] = mn[0][j] = mx[0][j - 1] * grid[0][j];
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        long long val = grid[i][j];

        long long a = mx[i - 1][j] * val;
        long long b = mn[i - 1][j] * val;
        long long c = mx[i][j - 1] * val;
        long long d = mn[i][j - 1] * val;

        mx[i][j] = max({a, b, c, d});
        mn[i][j] = min({a, b, c, d});
      }
    }

    long long ans = mx[n - 1][m - 1];
    if (ans < 0)
      return -1;

    return ans % MOD;
  }
};
