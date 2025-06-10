class Solution {
public:
  int compress(vector<char> &chars) {
    int ans = 0;
    int c = 0, n = chars.size();
    while (c <= n - 1) {
      int cc = 1;
      char sc = chars[c];
      while (c < n - 1 && chars[c + 1] == chars[c]) {
        c++;
        cc++;
      }

      chars[ans++] = sc;
      // cout << sc << ' ' << cc << ' ' << ans << '\n';
      if (cc > 1) {
        string s = to_string(cc);
        for (char sc : s)
          chars[ans++] = sc;
      }
      c++;
    }
    return ans;
  }
};
