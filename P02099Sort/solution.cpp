class Solution {
public:
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    vector<pair<int, int>> p;
    for (int i = 0; i < nums.size(); i++)
      p.push_back({nums[i], i});
    sort(p.begin(), p.end());
    vector<int> ans;
    for (int i = 0; i < k; i++) {
      ans.push_back(p[p.size() - 1 - i].second);
    }

    sort(ans.begin(), ans.end());

    vector<int> ans2;
    for (auto a : ans) {
      ans2.push_back(nums[a]);
    }

    return ans2;
  }
};
