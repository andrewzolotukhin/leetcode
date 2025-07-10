class Solution {
private:
  int solve(vector<int> &prices, vector<vector<int>> &dp, int day,
            bool canBuy) {
    int n = prices.size();
    if (day >= n)
      return 0;
    if (dp[day][canBuy] != -1) {
      return dp[day][canBuy];
    }

    int ans = solve(prices, dp, day + 1, canBuy);

    if (canBuy) {
      ans = max(ans, solve(prices, dp, day + 1, false) - prices[day]);
    } else {
      ans = max(ans, solve(prices, dp, day + 2, true) + prices[day]);
    }

    return dp[day][canBuy] = ans;
  }

public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(2, -1));

    return solve(prices, dp, 0, true);
  }
};
