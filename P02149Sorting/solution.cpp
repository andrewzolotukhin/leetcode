class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    vector<pair<int, int>> ps;
    for (int i = 0; i < nums.size(); i++) {
      ps.push_back({nums[i], i});
    }

    auto comp = [&](pair<int, int> &a, pair<int, int> &b) {
      if (a.first < 0 && b.first > 0)
        return false;
      if (a.first > 0 && b.first < 0)
        return true;
      return a.second < b.second;
    };

    sort(ps.begin(), ps.end(), comp);
    vector<int> ans;

    for (int i = 0; i < nums.size() / 2; i++) {
      ans.push_back(ps[i].first);
      ans.push_back(ps[nums.size() / 2 + i].first);
    }
    return ans;
  }
};
