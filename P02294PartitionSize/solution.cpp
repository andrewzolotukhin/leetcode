class Solution {
public:
  int partitionArray(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = 1;
    int r = nums[0];
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] - r > k) {
        ans++;
        r = nums[i];
      }
    }

    return ans;
  }
};
