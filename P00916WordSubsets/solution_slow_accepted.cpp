#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    vector<unordered_map<char, int>> freq(words1.size(),
                                          unordered_map<char, int>());
    unordered_map<char, int> freq2;
    vector<string> result;

    for (int i = 0; i < words1.size(); i++) {
      for (int j = 0; j < words1[i].size(); j++) {
        freq[i][words1[i][j]]++;
      }
    }

    for (int i = 0; i < words2.size(); i++) {
      unordered_map<char, int> curr;
      for (int j = 0; j < words2[i].size(); j++) {
        curr[words2[i][j]]++;
      }
      for (auto [k, v] : curr) {
        freq2[k] = max(freq2[k], v);
      }
    }

    for (int i = 0; i < words1.size(); i++) {
      bool isGood = true;
      for (auto [k, v] : freq2) {
        if (v > freq[i][k]) {
          isGood = false;
          break;
        }
      }
      if (isGood) {
        result.push_back(words1[i]);
      }
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  Solution s;

  int n, m;
  cin >> n >> m;

  vector<string> words1, words2;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    words1.push_back(s);
  }

  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    words2.push_back(s);
  }

  auto result = s.wordSubsets(words1, words2);

  for (auto s : result) {
    cout << s << '\n';
  }
}
