class Solution {
public:
  vector<string> removeAnagrams(vector<string> &words) {
    for (int i = 1; i < words.size(); i++) {
      string f = words[i - 1];
      string s = words[i];
      sort(f.begin(), f.end());
      sort(s.begin(), s.end());

      if (f == s) {
        words.erase(words.begin() + i, words.begin() + i + 1);
        i = 0;
      }
    }

    return words;
  }
};
