class Solution {
public:
  int maxIncreasingSubarrays(vector<int> &nums) {
    int pre = 0, curr = 1, ans = 0;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) {
        curr++;
      } else {
        pre = curr;
        curr = 1;
      }
      ans = max(ans, min(pre, curr));
      ans = max(ans, curr / 2);
    }

    return ans;
  }
};
