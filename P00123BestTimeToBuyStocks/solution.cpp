
class Solution {
private:
  vector<vector<vector<int>>> dp;
  int solve(vector<int> &prices, int day, int trans, int state) {
    int n = prices.size();
    if (day >= n || trans == 0)
      return 0;
    if (dp[state][trans][day] != -1)
      return dp[state][trans][day];

    int ans = solve(prices, day + 1, trans, state);
    if (state) {
      ans = max(ans, solve(prices, day + 1, trans - 1, 0) + prices[day]);
    } else {
      ans = max(ans, solve(prices, day + 1, trans, 1) - prices[day]);
    }
    return dp[state][trans][day] = ans;
  }

public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    dp.resize(2, vector<vector<int>>(3, vector<int>(n, -1)));
    return solve(prices, 0, 2, 0);
  }
};
