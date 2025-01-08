#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  class Solution {
  public:
    int countPrefixSuffixPairs(vector<string> &words) {
      int result = 0;

      for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
          if (words[j].size() < words[i].size()) {
            continue;
          }
          bool isGood = true;
          for (int k = 0; k < words[i].size(); k++) {
            if (words[i][k] != words[j][k]) {
              isGood = false;
              break;
            }
          }
          if (!isGood)
            continue;

          for (int k = 0; k < words[i].size(); k++) {
            if (words[i][k] !=
                words[j][words[j].size() - words[i].size() + k]) {
              isGood = false;
              break;
            }
          }
          if (!isGood)
            continue;
          result++;
        }
      }
      return result;
    }
  };

  int n;
  cin >> n;
  vector<string> strs;

  while (n--) {
    string s;
    cin >> s;
    strs.push_back(s);
  }

  Solution s;

  cout << s.countPrefixSuffixPairs(strs) << '\n';
}
