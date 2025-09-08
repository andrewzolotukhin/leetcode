class Solution {
private:
  void solve(string &s, int n, vector<string> &ans) {
    if (s.size() == n) {
      ans.push_back(s);
      return;
    }
    if (s.size() == 0) {
      s += "0";
      solve(s, n, ans);
      s.back() = '1';
      solve(s, n, ans);
      return;
    }

    if (s.back() == '0') {
      s.push_back('1');
      solve(s, n, ans);
      s.pop_back();
    } else {
      s.push_back('1');
      solve(s, n, ans);
      s.pop_back();
      s.push_back('0');
      solve(s, n, ans);
      s.pop_back();
    }
  }

public:
  vector<string> validStrings(int n) {
    vector<string> ans;
    string s = "";
    solve(s, n, ans);
    return ans;
  }
};
