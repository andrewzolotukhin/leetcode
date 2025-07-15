class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int m = 0, ans = 0, c = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > m) {
        m = nums[i];
        c = 1;
        ans = 0;
      } else if (nums[i] == m) {
        c++;
      } else {
        c = 0;
      }
      ans = max(ans, c);
    }

    return ans;
  }
};
