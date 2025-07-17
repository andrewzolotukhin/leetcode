class Solution {
public:
  int maximumLength(vector<int> &nums, int k) {
    vector<vector<int>> dp(k, vector<int>(k, 0));
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      int rem = nums[i] % k;

      for (int j = 0; j < k; j++) {
        dp[j][rem] = dp[rem][j] + 1;
        ans = max(ans, dp[j][rem]);
      }
    }

    return ans;
  }
};
