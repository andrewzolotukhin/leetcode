#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    if (word1 == word2) {
      return 0;
    }

    if (word1.size() == 0) {
      return word2.size();
    }

    if (word2.size() == 0) {
      return word1.size();
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++) {
      dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = min(
            dp[i - 1][j] + 1,
            min(dp[i][j - 1] + 1,
                dp[i - 1][j - 1] + ((word1[i - 1] == word2[j - 1]) ? 0 : 1)));
      }
    }

    return dp[n][m];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s1, s2;
  cin >> s1 >> s2;
  cout << Solution().minDistance(s1, s2) << '\n';
}
