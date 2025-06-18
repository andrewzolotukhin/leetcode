class Solution {
public:
  vector<vector<int>> divideArray(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    bool isBad = false;
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i += 3) {
      if (nums[i + 2] - nums[i] > k) {
        isBad = true;
        break;
      }
      ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
    }

    if (isBad)
      return {};
    return ans;
  }
};
