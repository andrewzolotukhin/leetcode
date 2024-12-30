#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numWays(vector<string> &words, string target) {
    int n = words.size();
    int m = words[0].size();
    vector<vector<int>> freq(m, vector<int>(26, 0));
    vector<vector<int>> dp(m, vector<int>(target.size(), -1));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int l = words[j][i] - 'a';
        freq[i][l]++;
      }
    }

    return getNum(m, target, 0, 0, freq, dp);
  }

  int getNum(int wordSize, string target, int targetIndex, int wordIndex,
             vector<vector<int>> &freq, vector<vector<int>> &dp) {
    int divider = 1000000007;
    long long result = 0L;

    if (targetIndex == target.size())
      return 1;
    if (wordIndex == wordSize ||
        (wordSize - wordIndex < (target.size() - targetIndex)))
      return 0;

    if (dp[wordIndex][targetIndex] != -1)
      return dp[wordIndex][targetIndex];

    int freqId = target[targetIndex] - 'a';

    result += ((long long)freq[wordIndex][freqId] *
               (long long)getNum(wordSize, target, targetIndex + 1,
                                 wordIndex + 1, freq, dp)) %
              divider;

    result += (long long)getNum(wordSize, target, targetIndex, wordIndex + 1,
                                freq, dp) %
              divider;

    dp[wordIndex][targetIndex] = result % divider;

    return dp[wordIndex][targetIndex];
  }
};

int main() {
  // cin.tie(0)->sync_with_stdio(0);
  // cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  vector<string> strs;

  string target;

  cin >> target;

  while (n--) {
    string s;
    cin >> s;
    strs.push_back(s);
  }

  Solution sol;

  cout << sol.numWays(strs, target) << endl;
}
