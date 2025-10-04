class Solution {
public:
  string stringHash(string s, int k) {
    int p = s.size() / k;
    string res(p, ' ');
    for (int i = 0; i < p; i++) {
      int c = 0;
      for (int j = 0; j < k; j++) {
        c += s[i * k + j] - 'a';
      }
      c = c % 26;
      res[i] = (char)c + 'a';
    }

    return res;
  }
};
