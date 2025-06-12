class Solution {
public:
  int maxAdjacentDistance(vector<int> &nums) {
    int ans = INT_MIN;
    int n = nums.size();
    for (int i = 0; i <= nums.size(); i++) {
      ans = max(ans, abs(nums[i % n] - nums[(i + 1) % n]));
    }
    return ans;
  }
};
