class Solution {
public:
  int sortPermutation(vector<int> &nums) {
    int ans = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i) {
        if (ans == INT_MAX) {
          ans = nums[i];
        } else {
          ans &= nums[i];
        }
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};
