class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans = {{}};

    int pos = 0;
    int n = nums.size();
    while (pos < n) {
      int dupc = 0;
      while (pos < n - 1 && nums[pos] == nums[pos + 1]) {
        pos++;
        dupc++;
      }

      int cs = ans.size();
      for (int i = 0; i < cs; i++) {
        auto sub = ans[i];
        for (int j = 0; j <= dupc; j++) {
          sub.push_back(nums[pos]);
          ans.push_back(sub);
        }
      }
      pos++;
    }

    return ans;
  }
};
