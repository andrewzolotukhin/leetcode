class Solution {
private:
  unordered_map<int, bool> memo;
  bool isPalindrome(string &s, int start, int end) {
    int key = start | (end << 10);
    if (memo.count(key))
      return memo[key];
    for (int i = 0; i <= (end + 1 - start) / 2; i++) {
      if (s[start + i] != s[end - i])
        return memo[key] = false;
    }
    return memo[key] = true;
  }
  void solve(string &s, int start, vector<string> &curr,
             vector<vector<string>> &ans) {
    if (start >= s.size()) {
      ans.push_back(curr);
      return;
    }
    for (int i = start; i < s.size(); i++) {
      if (isPalindrome(s, start, i)) {
        curr.push_back(s.substr(start, i - start + 1));
        solve(s, i + 1, curr, ans);
        curr.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> r;
    solve(s, 0, r, ans);
    return ans;
  }
};
