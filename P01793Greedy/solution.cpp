class Solution {
public:
  int maximumScore(vector<int> &nums, int k) {
    int minV = nums[k], l = k, r = k, ans = nums[k], n = nums.size();

    do {
      if (l > 0 && r < n - 1) {
        if (nums[l - 1] >= nums[r + 1]) {
          l--;
        } else {
          r++;
        }
      } else if (l == 0 && r < n - 1) {
        r++;
      } else if (r == n - 1 && l > 0) {
        l--;
      }
      minV = min(minV, min(nums[l], nums[r]));
      ans = max(ans, minV * (r - l + 1));
    } while (l > 0 || r < n - 1);

    return ans;
  }
};
