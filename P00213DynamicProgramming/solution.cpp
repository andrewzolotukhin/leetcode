class Solution {
private:
  int solve(vector<int> &nums, int l, int r) {
    int ans = 0;
    int prev = 0;

    for (int i = l; i <= r; i++) {
      int t = ans;
      ans = max(ans, prev + nums[i]);
      prev = t;
    }

    return ans;
  }

public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    if (nums.size() == 2)
      return max(nums[0], nums[1]);

    return max(solve(nums, 0, nums.size() - 2),
               solve(nums, 1, nums.size() - 1));
  }
};
