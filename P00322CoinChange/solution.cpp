class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, 10001);
    dp[0] = 0;
    for (int i = 0; i < amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if ((0LL + i + coins[j]) > (long long)amount)
          continue;
        dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
      }
    }

    return (dp[amount] == 10001) ? -1 : dp[amount];
  }
};
