class Solution {
private:
  map<pair<int, int>, bool> memo;
  bool solve(string &s1, string &s2, string &s3, int p1, int p2, int p3) {
    pair<int, int> key = {p1, p2};
    if (p3 == s3.size())
      return true;
    if (memo.count(key))
      return memo[key];
    bool ans = false;

    int n = s1.size();
    int m = s2.size();

    if (p1 < n && s1[p1] == s3[p3]) {
      ans |= solve(s1, s2, s3, p1 + 1, p2, p3 + 1);
    }
    if (p2 < m && s2[p2] == s3[p3]) {
      ans |= solve(s1, s2, s3, p1, p2 + 1, p3 + 1);
    }
    return memo[key] = ans;
  }

public:
  bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size(), m = s2.size(), k = s3.size();
    if (n == m && n == k && n == 0)
      return true;
    if (s1.size() + s2.size() != s3.size())
      return false;
    return solve(s1, s2, s3, 0, 0, 0);
  }
};
