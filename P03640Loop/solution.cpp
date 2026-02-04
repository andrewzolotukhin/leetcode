class Solution {
public:
  long long maxSumTrionic(vector<int> &nums) {
    int n = nums.size(), p, q, j;
    long long ms, s, r, ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
      j = i + 1;
      r = 0;
      for (; j < n && nums[j - 1] < nums[j]; j++)
        ;
      p = j - 1;
      if (p == i)
        continue;

      r += nums[p] + nums[p - 1];
      for (; j < n && nums[j - 1] > nums[j]; j++) {
        r += nums[j];
      }
      q = j - 1;
      if (q == p || q == n - 1 || (nums[j] <= nums[q])) {
        i = q;
        continue;
      }
      r += nums[q + 1];
      ms = 0;
      s = 0;
      for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
        s += nums[k];
        ms = max(ms, s);
      }
      r += ms;
      ms = 0;
      s = 0;
      for (int k = p - 2; k >= i; k--) {
        s += nums[k];
        ms = max(ms, s);
      }
      r += ms;
      ans = max(ans, r);
      i = q - 1;
    }
    return ans;
  }
};
