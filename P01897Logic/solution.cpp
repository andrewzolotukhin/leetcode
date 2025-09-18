class Solution {
public:
  bool makeEqual(vector<string> &words) {
    vector<int> freq(26, 0);
    for (string w : words) {
      for (char c : w) {
        freq[c - 'a']++;
      }
    }

    for (int i = 0; i < 26; i++) {
      if (freq[i] % words.size() != 0)
        return false;
    }
    return true;
  }
};
