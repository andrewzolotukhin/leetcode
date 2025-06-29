class Solution {
private:
  int solve(vector<int> &prices, int state, int day, vector<vector<int>> &memo,
            int fee) {
    if (day >= prices.size())
      return 0;
    if (memo[day][state] != -1)
      return memo[day][state];

    int ans = 0;

    if (state) {

      int notBuy = solve(prices, 1, day + 1, memo, fee);
      int buy = solve(prices, 0, day + 1, memo, fee) - prices[day];
      ans = max(buy, notBuy);
    } else {
      int sell = solve(prices, 1, day + 1, memo, fee) + prices[day] - fee;
      int notSell = solve(prices, 0, day + 1, memo, fee);
      ans = max(sell, notSell);
    }
    return memo[day][state] = ans;
  }

public:
  int maxProfit(vector<int> &prices, int fee) {
    vector<vector<int>> memo(prices.size(), vector<int>(2, -1));
    return solve(prices, 1, 0, memo, fee);
  }
};
