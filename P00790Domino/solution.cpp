class Solution {
public:
  int numTilings(int n) {
    int mod = int(1e9) + 7;
    vector<long long> dp(n + 6, 0);
    dp[0] = 1LL;
    dp[1] = 1LL;
    dp[2] = 2LL;
    dp[3] = 5LL;

    for (int i = 4; i <= n; i++) {
      dp[i] = (2 * dp[i - 1] + dp[i - 3]) % mod;
    }

    return dp[n] % mod;
  }
};
