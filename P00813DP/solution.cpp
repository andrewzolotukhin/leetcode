class Solution {
private:
  double solve(unordered_map<int, double> &memo, vector<int> &nums, int idx,
               int rem) {
    int key = (idx << 10) | rem;
    int n = nums.size();
    if (idx == n)
      return rem == 0 ? 0.0 : -1e18;

    if (memo.count(key))
      return memo[key];
    if (rem == 0) {
      double s = 0;
      for (int i = idx; i < n; i++)
        s += nums[i];
      return memo[key] = s / (n - idx);
    }

    double best = 0;
    double s = 0;

    for (int i = idx; i < n; i++) {
      s += nums[i];
      double avg = s / (i - idx + 1);
      best = max(best, avg + solve(memo, nums, i + 1, rem - 1));
    }
    return memo[key] = best;
  }

public:
  double largestSumOfAverages(vector<int> &nums, int k) {
    unordered_map<int, double> ans;
    return solve(ans, nums, 0, k - 1);
  }
};
