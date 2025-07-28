class Solution {
public:
  int countMaxOrSubsets(vector<int> &nums) {
    int target = 0;
    for (auto v : nums)
      target |= v;

    int n = nums.size();

    int t = 1 << n;
    int ans = 0;

    for (int i = 0; i < t; i++) {
      int tot = 0;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j))
          tot |= nums[j];
      }
      if (tot == target)
        ans++;
    }

    return ans;
  }
};
