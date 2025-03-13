class Solution {
public:
  string minWindow(string s, string t) {
    int m = s.size();
    int n = t.size();

    if (n > m)
      return "";

    map<char, int> freq;

    for (int i = 0; i < n; i++)
      freq[(char)t[i]]++;

    int l = 0, r = 0;
    map<char, int> cfreq;

    auto areAllIncluded = [&]() -> bool {
      for (auto [f, fc] : freq) {
        if (cfreq[(char)f] < fc)
          return false;
      }
      return true;
    };

    int minLen = INT_MAX;
    int ansL, ansR;
    string ans = "";

    cfreq[s[l]] = 1;

    while (r < m) {
      if (r - l + 1 >= n && areAllIncluded()) {
        if (r - l + 1 < minLen) {
          minLen = r - l + 1;
          ansL = l;
          ansR = r;
        }
        cfreq[(char)s[l++]]--;
        continue;
      }

      cfreq[(char)s[++r]]++;
    }

    if (minLen != INT_MAX) {
      ans = s.substr(ansL, ansR - ansL + 1);
    }
    return ans;
  }
};
