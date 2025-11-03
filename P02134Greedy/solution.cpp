class Solution {
public:
  int minSwaps(vector<int> &nums) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    int total = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 1)
        total++;
      prefix[i + 1] = prefix[i] + nums[i];
    }
    if (total == 0 || total == n || total == n - 1 || total == 1)
      return 0;
    int ans = n;
    for (int i = 0; i < n; i++) {
      int l = i, r = (i + total - 1) % n;
      int s;
      if (l < r) {
        s = total - (prefix[r + 1] - prefix[l]);
      } else {
        s = total - (prefix[n] - (prefix[l] - prefix[r + 1]));
      }
      ans = min(ans, s);
    }
    return ans;
  }
};
