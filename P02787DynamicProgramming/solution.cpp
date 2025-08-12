long long mod = int(1e9) + 7;

class Solution {
public:
  int numberOfWays(int n, int x) {
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
      long long p = pow(i, x);
      for (int j = 0; j <= n; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= p) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % mod;
        }
      }
    }

    return dp[n][n];
  }
};
