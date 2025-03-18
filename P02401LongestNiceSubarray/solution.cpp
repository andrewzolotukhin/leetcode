class Solution {
private:
  bool containsNiceSubarray(vector<int> &nums, int m) {
    int mask = 0;
    int n = nums.size();
    if (m <= 1)
      return true;

    for (int i = 0; i <= n - m; i++) {
      mask = 0;
      bool hasArray = true;
      for (int j = 0; j < m; j++) {
        if ((mask & nums[i + j]) == 0) {
          mask |= nums[i + j];
        } else {
          hasArray = false;
          break;
        }
      }
      if (hasArray)
        return true;
    }

    return false;
  }

public:
  int longestNiceSubarray(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return 1;

    int l = 0, h = n;
    int ans = 1;

    while (l <= h) {
      int m = (l + h) / 2;
      if (containsNiceSubarray(nums, m)) {
        l = m + 1;
        ans = m;
      } else {
        h = m - 1;
      }
    }

    return ans;
  }
};
