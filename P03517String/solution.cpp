class Solution {
public:
  string smallestPalindrome(string s) {
    if (s.size() <= 1)
      return s;
    sort(s.begin(), s.begin() + s.size() / 2);
    string h1 = s.substr(0, (int)s.size() / 2);
    string h2 = h1;
    reverse(h2.begin(), h2.end());
    if (s.size() & 1)
      h1 += s[s.size() / 2];
    h1 += h2;
    return h1;
  }
};
