class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> rows(n, 0), cols(m, 0);

    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        if (grid[r][c]) {
          rows[r] += 2;
          cols[c] += 2;
        }
      }
    }

    vector<vector<int>> ans(n, vector<int>(m, -n - m));
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        ans[r][c] += rows[r] + cols[c];
      }
    }

    return ans;
  }
};
