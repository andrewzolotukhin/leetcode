class Solution {
public:
  int minimumSubarrayLength(vector<int> &nums, int k) {
    int minL = INT_MAX;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (j - i + 1 > minL)
          continue;
        int c = 0;
        for (int l = i; l <= j; l++) {
          c |= nums[l];
        }
        if (c >= k) {
          minL = min(minL, j - i + 1);
        }
      }
    }

    return minL == INT_MAX ? -1 : minL;
  }
};
