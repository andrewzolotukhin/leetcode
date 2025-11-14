class Solution {
public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
    vector<vector<int>> change(n + 1, vector<int>(n + 1, 0));

    for (auto &q : queries) {
      int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
      change[r1][c1]++;
      change[r2 + 1][c1]--;
      change[r1][c2 + 1]--;
      change[r2 + 1][c2 + 1]++;
    }

    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int left = (i == 0) ? 0 : ans[i - 1][j];
        int top = (j == 0) ? 0 : ans[i][j - 1];
        int leftTop = (i == 0 || j == 0) ? 0 : ans[i - 1][j - 1];
        ans[i][j] = change[i][j] + left + top - leftTop;
      }
    }

    return ans;
  }
};
