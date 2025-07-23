class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans = {{1}};
    while (ans.size() < numRows) {
      vector<int> r = {1};
      for (int i = 0; i < ans[ans.size() - 1].size() - 1; i++) {
        r.push_back(ans[ans.size() - 1][i] + ans[ans.size() - 1][i + 1]);
      }

      r.push_back(1);
      ans.push_back(r);
    }

    return ans;
  }
};
