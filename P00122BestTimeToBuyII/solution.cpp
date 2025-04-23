class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; i++) {
      diff[i] = prices[i + 1] - prices[i];
    }

    int ans = 0;
    for (auto c : diff) {
      if (c > 0)
        ans += c;
    }
    return ans;
  }
};
