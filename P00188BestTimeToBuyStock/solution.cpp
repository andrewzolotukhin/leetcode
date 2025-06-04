class Solution {
private:
  vector<vector<vector<int>>> memo;
  int solve(vector<int> &prices, int state, int transLeft, int day) {
    int n = prices.size();
    if (transLeft <= 0 || day >= n)
      return 0;
    if (memo[state][transLeft][day] != -1)
      return memo[state][transLeft][day];

    auto res = solve(prices, state, transLeft, day + 1);
    if (state == 0) {
      res = max(res, solve(prices, 1, transLeft, day + 1) - prices[day]);
    } else {
      res = max(res, solve(prices, 0, transLeft - 1, day + 1) + prices[day]);
    }

    return memo[state][transLeft][day] = res;
  }

public:
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    memo.resize(2, vector<vector<int>>(k + 1, vector<int>(n, -1)));

    return solve(prices, 0, k, 0);
  }
};
