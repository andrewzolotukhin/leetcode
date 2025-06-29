int MOD = int(1e9) + 7;
class Solution {
public:
  int numSubseq(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    int l = 0, r = n - 1;
    vector<int> p(n, 1);
    for (int i = 1; i < n; i++) {
      p[i] = (p[i - 1] * 2) % MOD;
    }

    while (l <= r) {
      if (nums[l] + nums[r] > target) {
        r--;
      } else {
        ans = (ans + p[r - l]) % MOD;
        l++;
      }
    }

    return ans;
  }
};
