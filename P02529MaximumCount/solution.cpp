class Solution {
public:
  int maximumCount(vector<int> &nums) {
    int fz, lz, n = nums.size();
    lz = n - (upper_bound(nums.begin(), nums.end(), 0) - nums.begin());
    fz = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
    return max(lz, fz);
  }
};
