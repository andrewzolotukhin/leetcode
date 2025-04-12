class Solution {
public:
  int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
    int n = nums.size();
    int ans = 0, low = 0, inb = 0, lasti = -1;
    for (int i = 0; i < n; i++) {
      if (nums[i] < left) {
        if (inb > 0) {
          ans += inb + low;
          ans -= i - lasti - 1;
        }
        low++;
      } else if (nums[i] >= left && nums[i] <= right) {
        ans += inb + low + 1;
        inb++;
        lasti = i;
      } else {
        low = 0;
        inb = 0;
      }
    }

    return ans;
  }
};
