class Solution {
public:
  string thousandSeparator(int n) {
    string ans = "";

    string s = to_string(n);
    for (int i = 0; i < s.size(); i++) {
      if (i > 0 && i % 3 == 0) {
        ans += '.';
      }
      ans += s[s.size() - 1 - i];
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
