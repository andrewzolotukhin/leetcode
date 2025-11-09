class Solution {
public:
  string licenseKeyFormatting(string s, int k) {
    int len = 0;
    int last = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '-') {
        len++;
        last = i;
      }
    }

    int fg = len % k;
    cout << fg << '\n';
    string ans = "";
    for (int i = 0; i <= last; i++) {
      if (s[i] == '-')
        continue;
      ans += toupper(s[i]);
      fg--;
      if (fg == 0 || k == 1) {
        fg = k;
        if (i != last) {
          ans += '-';
        }
      }
      if (fg < 0)
        fg = k - 1;
    }
    return ans;
  }
};
