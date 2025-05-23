class Solution {
private:
  long long solve(int i, int parity, vector<int> &nums, int k,
                  vector<vector<long long>> &dp) {
    int n = nums.size();
    if (i == n) {
      return parity ? 0 : INT_MIN;
    }

    if (dp[i][parity] != -1) {
      return dp[i][parity];
    }

    long long ans1 = nums[i] + solve(i + 1, parity, nums, k, dp);
    long long ans2 = (nums[i] ^ k) + solve(i + 1, parity ^ 1, nums, k, dp);
    return dp[i][parity] = max(ans1, ans2);
  }

public:
  long long maximumValueSum(vector<int> &nums, int k,
                            vector<vector<int>> &edges) {
    int n = nums.size();
    vector<vector<long long>> dp(n, vector<long long>(2, -1));
    return solve(0, 1, nums, k, dp);
  }
};
