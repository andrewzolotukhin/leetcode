class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    int ans = n;
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
      prefix[i] = prefix[i - 1] + nums[i - 1];
    if (prefix[n] < target)
      return 0;
    int l = 0, r = 0;
    while (r < n) {
      int sum = prefix[r + 1] - prefix[l];
      while (sum >= target && l <= r) {
        if (r - l + 1 < ans) {
          ans = r - l + 1;
        }
        l++;
        sum = prefix[r + 1] - prefix[l];
      }
      r++;
    }
    return ans;
  }
};
