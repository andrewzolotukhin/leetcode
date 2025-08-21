class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j == 0) {
          dp[i][j] = mat[i][j];
          continue;
        }
        dp[i][j] = (mat[i][j] == 0) ? 0 : (dp[i][j - 1] + 1);
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int r = dp[i][j];
        for (int k = i; k >= 0; k--) {
          r = min(dp[k][j], r);
          if (r == 0) {
            break;
          }
          ans += r;
        }
      }
    }

    return ans;
  }
};
