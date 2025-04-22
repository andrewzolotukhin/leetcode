class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    int mi = prices[0];

    int n = prices.size();
    for (int i = 0; i < n; i++) {
      ans = max(prices[i] - mi, ans);
      mi = min(prices[i], mi);
    }

    return ans;
  }
};
