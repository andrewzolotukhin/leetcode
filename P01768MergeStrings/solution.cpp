class Solution {
private:
  string solve(string &word1, string &word2, int start) {
    string ans(word1.size() + word2.size(), ' ');
    int c = 0;
    int p = start;
    int l = 0, r = 0;

    while (c < ans.size()) {
      if ((p & 1) && r < word2.size()) {
        ans[c++] = word2[r++];
      } else {
        ans[c++] = word1[l++];
      }
      p = 1 - p;
    }
    return ans;
  }

public:
  string mergeAlternately(string word1, string word2) {
    return word1.size() >= word2.size() ? solve(word1, word2, 0)
                                        : solve(word2, word1, 1);
  }
};
