class Solution {
public:
  int countBinarySubstrings(string s) {
    int pl = 0, cl = 1, pv = s[0], ans = 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] != s[i - 1]) {
        ans += min(cl, pl);
        pl = cl;
        cl = 1;
      } else {
        cl++;
      }
    }
    ans += min(cl, pl);
    return ans;
  }
};
