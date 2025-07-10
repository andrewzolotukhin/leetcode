class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> c = nums;
    sort(c.begin(), c.end());

    vector<int> ans(nums.size());

    for (int i = 0; i < nums.size(); i++) {
      ans[i] = lower_bound(c.begin(), c.end(), nums[i]) - c.begin();
    }
    return ans;
  }
};
