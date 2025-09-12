class Solution {
public:
  vector<int> shuffle(vector<int> &nums, int n) {
    vector<int> ans(n * 2);
    for (int i = 0; i < n; i++) {
      ans[i * 2] = nums[i];
    }

    for (int i = 0; i < n; i++) {
      ans[i * 2 + 1] = nums[n + i];
    }

    return ans;
  }
};
