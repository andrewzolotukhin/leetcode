class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size(), m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = i;
    }

    for (int i = 0; i <= m; i++) {
      dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (str1[i - 1] == str2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
      }
    }

    string result = "";

    int r = n, c = m;

    while (r > 0 && c > 0) {
      if (str1[r - 1] == str2[c - 1]) {
        result += str1[r - 1];
        r--;
        c--;
      } else if (dp[r - 1][c] < dp[r][c - 1]) {
        result += str1[r - 1];
        r--;
      } else {
        result += str2[c - 1];
        c--;
      }
    }

    for (int i = r; i > 0; i--) {
      result += str1[i - 1];
    }

    for (int i = c; i > 0; i--) {
      result += str2[i - 1];
      c--;
    }

    reverse(result.begin(), result.end());

    return result;
  }
};
