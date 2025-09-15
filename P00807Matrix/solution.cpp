class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> mx1(m), mx2(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        mx1[j] = max(mx1[j], grid[i][j]);
        mx2[i] = max(mx2[i], grid[i][j]);
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans += min(mx1[j], mx2[i]) - grid[i][j];
      }
    }
    return ans;
  }
};
