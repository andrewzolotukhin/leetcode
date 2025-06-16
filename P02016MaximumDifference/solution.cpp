class Solution {
public:
  int maximumDifference(vector<int> &nums) {
    int n = nums.size();
    int prevMin = nums[0];
    int ans = -1;

    for (int i = 1; i < n; i++) {
      if (nums[i] > prevMin) {
        ans = max(nums[i] - prevMin, ans);
      } else {
        prevMin = nums[i];
      }
    }

    return ans;
  }
};
