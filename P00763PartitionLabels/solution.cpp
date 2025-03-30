class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> freq(26, 0);

    for (auto c : s) {
      freq[c - 'a']++;
    }

    vector<int> parts;
    vector<int> cFreq(26, 0);
    int endIndex = s.size();
    for (int i = s.size() - 1; i >= 0; i--) {
      int c = s[i] - 'a';

      freq[c]--;
      cFreq[c]++;

      bool isGood = true;

      for (int i = 0; i < 26; i++) {
        if (cFreq[i] > 0) {
          if (freq[i] > 0) {
            isGood = false;
            break;
          }
        }
      }

      if (isGood) {
        parts.push_back(endIndex - i);
        endIndex = i;
        for (int i = 0; i < 26; i++)
          cFreq[i] = 0;
      }
    }

    return vector<int>(parts.rbegin(), parts.rend());
  }
};
