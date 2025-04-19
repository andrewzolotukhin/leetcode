class Solution {
public:
  int countPairs(vector<int> &nums, int target) {
    int ans = 0, n = nums.size();
    sort(nums.begin(), nums.end());

    int l = 0, r = n - 1;

    while (l < r) {
      if (nums[l] + nums[r] < target) {
        ans += r - l;
        l++;
      } else {
        r--;
      }
    }

    return ans;
  }
};
