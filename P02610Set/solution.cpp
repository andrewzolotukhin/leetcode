class Solution {
public:
  vector<vector<int>> findMatrix(vector<int> &nums) {
    vector<set<int>> res = {{}};
    for (auto v : nums) {
      bool added = false;

      for (int i = 0; i < res.size(); i++) {
        if (res[i].count(v) == 0) {
          added = true;
          res[i].insert(v);
          break;
        }
      }

      if (!added) {
        res.push_back({v});
      }
    }

    vector<vector<int>> ans;
    for (auto s : res) {
      ans.push_back(vector<int>(s.begin(), s.end()));
    }

    return ans;
  }
};
