class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> freq(26, 0);
    for (auto c : ransomNote)
      freq[c - 'a']++;
    for (auto c : magazine)
      freq[c - 'a']--;
    for (int i = 0; i < 26; i++) {
      if (freq[i] > 0)
        return false;
    }
    return true;
  }
};
