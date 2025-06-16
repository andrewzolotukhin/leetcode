class Solution {
private:
  string solve(string &s, int &idx) {
    string ans;
    while (idx < s.size() && s[idx] != ']') {
      if (s[idx] >= '0' && s[idx] <= '9') {
        int c = 0;
        while (idx < s.size() && (s[idx] >= '0' && s[idx] <= '9')) {
          c = c * 10 + s[idx++] - '0';
        }
        idx++;
        string ch = solve(s, idx);
        idx++;

        while (c--) {
          ans += ch;
        }
      } else {
        ans += s[idx];
        idx++;
      }
    }
    return ans;
  }

public:
  string decodeString(string s) {
    int i = 0;
    return solve(s, i);
  }
};
