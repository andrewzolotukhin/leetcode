pair<int, int> prefix[101][26];

class Solution {
public:
  string longestNiceSubstring(string s) {
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < 26; j++) {
        if (s[i] == 'a' + j) {
          prefix[i + 1][j].first = prefix[i][j].first + 1;
        } else {
          prefix[i + 1][j].first = prefix[i][j].first;
        }

        if (s[i] == 'A' + j) {
          prefix[i + 1][j].second = prefix[i][j].second + 1;
        } else {
          prefix[i + 1][j].second = prefix[i][j].second;
        }
      }
    }

    string ans = "";
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
        int len = j - i + 1;
        if (len <= ans.size())
          continue;
        bool isGood = true;
        for (int k = 0; k < 26; k++) {
          int s = prefix[j + 1][k].first - prefix[i][k].first;
          int b = prefix[j + 1][k].second - prefix[i][k].second;
          if (s == 0 && b == 0)
            continue;
          if (s != 0 && b != 0)
            continue;
          isGood = false;
          break;
        }
        if (!isGood)
          continue;
        ans = s.substr(i, j - i + 1);
      }
    }

    return ans;
  }
};
