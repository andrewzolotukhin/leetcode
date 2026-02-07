class Solution {
public:
  string minimizeStringValue(string s) {
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++)
      if (s[i] != '?')
        freq[s[i] - 'a']++;

    string r = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '?')
        continue;

      int minf = INT_MAX, minfi = 0;
      for (int j = 0; j < 26; j++) {
        if (freq[j] < minf) {
          minf = freq[j];
          minfi = j;
        }
      }
      r += ('a' + minfi);
      freq[minfi]++;
    }
    sort(r.begin(), r.end());

    for (int i = 0, j = 0; i < s.size(); i++) {
      if (s[i] != '?')
        continue;
      s[i] = r[j++];
    }
    return s;
  }
};
