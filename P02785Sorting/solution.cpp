class Solution {
public:
  string sortVowels(string s) {
    vector<pair<char, int>> l;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
          s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
          s[i] == 'u' || s[i] == 'U') {
        l.push_back({s[i], i});
      }
    }

    sort(l.begin(), l.end());

    int i = 0, j = 0;

    while (j < l.size()) {
      if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
          s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
          s[i] == 'u' || s[i] == 'U') {
        s[i] = l[j++].first;
      }
      i++;
    }

    return s;
  }
};
