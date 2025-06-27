class Solution {
private:
  void solve(set<int> &used, vector<vector<int>> &ans, int rem, int k,
             int sf = 1) {
    if (rem == 0 && k == used.size()) {
      vector<int> a;
      for (auto v : used) {
        a.push_back(v);
      }
      ans.push_back(a);
      return;
    }
    if (sf > 9)
      return;

    for (int i = sf; i <= 9; i++) {
      if (used.count(i) || i > rem) {
        continue;
      }
      used.insert(i);
      solve(used, ans, rem - i, k, i + 1);
      used.erase(i);
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    set<int> used;
    solve(used, ans, n, k);
    return ans;
  }
};
