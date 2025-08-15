class Solution {
private:
  void solve(string &s, int index, vector<string> &curr,
             unordered_set<string> &dict, vector<string> &ans) {
    if (index >= s.size()) {
      string res = curr[0];
      for (int i = 1; i < curr.size(); i++) {
        res += " " + curr[i];
      }
      ans.push_back(res);
      return;
    }

    for (int i = index; i < s.size(); i++) {
      string cs = s.substr(index, i - index + 1);
      if (dict.count(cs)) {
        curr.push_back(cs);
        solve(s, i + 1, curr, dict, ans);
        curr.pop_back();
      }
    }
  }

public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    vector<string> ans;
    vector<string> curr;
    unordered_set<string> dict;
    for (const auto &w : wordDict)
      dict.insert(w);
    solve(s, 0, curr, dict, ans);
    return ans;
  }
};
