class Solution {
public:
  int numberOfSubstrings(string s) {
    int l = 0, r = 0, n = s.size(), res = 0;

    vector<int> cnts(3, 0);

    while (r < s.size()) {
      cnts[s[r] - 'a']++;

      while ((cnts[0] ? 1 : 0) + (cnts[1] ? 1 : 0) + (cnts[2] ? 1 : 0) == 3) {
        res += n - r;
        cnts[s[l] - 'a']--;
        l++;
      }
      r++;
    }

    return res;
  }
};
