class Solution {
public:
  double new21Game(int n, int k, int maxPts) {
    vector<double> dp(n + 1);
    dp[0] = 1;
    double v = k > 0 ? 1 : 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = v / maxPts;
      if (i < k) {
        v += dp[i];
      }
      if (i - maxPts >= 0 && i - maxPts < k) {
        v -= dp[i - maxPts];
      }
    }

    double ans = 0;
    for (int i = k; i <= n; i++)
      ans += dp[i];
    return ans;
  }
};
