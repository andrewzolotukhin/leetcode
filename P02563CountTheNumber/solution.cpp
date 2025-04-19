class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    // lower - nums[i]  <=  nums[j]  <= upper - nums[i]
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int l = 0, r = n - 1;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
      int lb = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
               nums.begin() - i;
      int ub =
          lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1) -
          nums.begin() - i;

      ans += (long long)(ub - lb);
    }

    return ans;
  }
};
