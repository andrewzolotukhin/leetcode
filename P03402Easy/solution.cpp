class Solution {
public:
  int minimumOperations(vector<vector<int>> &grid) {
    int ans = 0;
    int n = grid.size(), m = grid[0].size();

    for (int i = 0; i < m; i++) {
      int pv = grid[0][i];
      for (int j = 1; j < n; j++) {
        if (grid[j][i] <= pv) {
          ans += pv - grid[j][i] + 1;
          pv++;
        } else {
          pv = grid[j][i];
        }
      }
    }
    return ans;
  }
};
