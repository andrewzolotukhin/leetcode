class Solution {
private:
  unordered_map<int, int> memo;
  int dfs(vector<int> &nums1, vector<int> &nums2, int t, int b) {
    int key = ((t << 10) | b);
    if (memo.count(key))
      return memo[key];
    int n = nums1.size(), m = nums2.size();
    if (t >= n || b >= m)
      return 0;
    int ans = 0;
    for (int i = b; i < m; i++) {
      if (nums2[i] == nums1[t]) {
        ans = max(ans, 1 + dfs(nums1, nums2, t + 1, i + 1));
      }
    }
    ans = max(ans, dfs(nums1, nums2, t + 1, b));
    return memo[key] = ans;
  }

public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    return dfs(nums1, nums2, 0, 0);
  }
};
