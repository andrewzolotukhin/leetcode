class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
    int z = 0, o = 0;

    for (auto &s : strs) {
      z = 0, o = 0;
      for (auto &c : s) {
        if (c == '0') {
          z++;
        } else {
          o++;
        }
      }

      for (int i = m; i >= z; i--) {
        for (int j = n; j >= o; j--) {
          memo[i][j] = max(memo[i][j], memo[i - z][j - o] + 1);
        }
      }
    }

    return memo[m][n];
  }
};
