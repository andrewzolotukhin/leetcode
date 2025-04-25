class Solution {
public:
  int checkRecord(int n) {
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(2, vector<int>(3, 0)));
    dp[0][0][0] = 1;
    int mod = int(1e9) + 7;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 3; k++) {
          if (k < 2) {
            dp[i][j][k + 1] =
                ((long long)dp[i][j][k + 1] + (long long)dp[i - 1][j][k]) % mod;
          }
          if (j < 1) {
            dp[i][j + 1][0] =
                ((long long)dp[i - 1][j][k] + (long long)dp[i][j + 1][0]) % mod;
          }
          dp[i][j][0] =
              ((long long)dp[i][j][0] + (long long)dp[i - 1][j][k]) % mod;
        }
      }
    }

    int ans = 0;

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j <= 2; j++) {
        ans = ((long long)ans + (long long)dp[n][i][j]) % mod;
      }
    }

    return ans % mod;
  }
};
