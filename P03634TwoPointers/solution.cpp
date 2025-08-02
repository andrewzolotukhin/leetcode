int ans = 0;
class Solution {
public:
  int minRemoval(vector<int> &nums, int k) {
    ans = 0;
    sort(nums.begin(), nums.end());
    int l = 0;

    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
      while (nums[i] > (long long)k * nums[l]) {
        l++;
      }
      ans = max(ans, i - l + 1);
    }

    return nums.size() - ans;
  }
};
// 1, 2, 0, 2, 1
