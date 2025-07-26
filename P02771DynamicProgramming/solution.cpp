class Solution {
public:
  int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(2, 1));
    int prev1 = 1, prev2 = 1;
    int ans = 1;
    for (int i = 1; i < n; i++) {
      int c11 = nums1[i - 1] <= nums1[i] ? prev1 + 1 : 1;
      int c12 = nums1[i - 1] <= nums2[i] ? prev1 + 1 : 1;
      int c21 = nums2[i - 1] <= nums2[i] ? prev2 + 1 : 1;
      int c22 = nums2[i - 1] <= nums1[i] ? prev2 + 1 : 1;
      prev1 = max(c11, c22);
      prev2 = max(c12, c21);
      ans = max(ans, max(prev1, prev2));
    }

    return ans;
  }
};
