class Solution {
public:
  bool checkRecord(string s) {
    int l = 0, a = 0, n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A') {
        a++;
        if (a > 1)
          return false;
      } else if (s[i] == 'L') {
        if (i > 0 && s[i - 1] == 'L') {
          l++;
        } else {
          l = 0;
        }
        if (l > 1)
          return false;
      } else {
        l = 0;
      }
    }
    return true;
  }
};
