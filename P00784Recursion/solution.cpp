class Solution {
private:
  void solve(string &s, int index, vector<string> &ans) {
    if (index == s.size()) {
      ans.push_back(s);
      return;
    }

    if (s[index] >= '0' && s[index] <= '9') {
      solve(s, index + 1, ans);
      return;
    }

    if (s[index] >= 'a' && s[index] <= 'z') {
      s[index] -= 32;
      solve(s, index + 1, ans);
      s[index] += 32;
      solve(s, index + 1, ans);
    } else {
      s[index] += 32;
      solve(s, index + 1, ans);
      s[index] -= 32;
      solve(s, index + 1, ans);
    }
  }

public:
  vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    solve(s, 0, ans);
    return ans;
  }
};
