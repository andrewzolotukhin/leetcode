class Solution {
public:
  int alternatingSubarray(vector<int> &nums) {
    int n = nums.size();
    int ans = -1;
    int i = 1;

    while (i < n) {
      while (i < n && nums[i] - nums[i - 1] != 1)
        i++;
      int prev = -1;
      int len = 1;
      while (i < n && nums[i] - nums[i - 1] == -prev) {
        len++;
        prev = -prev;
        i++;
      }
      ans = max(ans, len);
    }

    return ans <= 1 ? -1 : ans;
  }
};
