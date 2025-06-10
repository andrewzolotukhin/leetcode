class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;

    int l = 0, r = n - 1;

    while (l < r) {
      if ((long long)k == 0LL + nums[l] + nums[r]) {
        ans++;
        l++;
        r--;
      } else if (0LL + nums[l] + nums[r] < k) {
        l++;
      } else {
        r--;
      }
    }

    return ans;
  }
};
