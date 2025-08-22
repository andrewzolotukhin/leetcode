class Solution {
public:
  int minimumArea(vector<vector<int>> &grid) {
    int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN,
        n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          minX = min(i, minX);
          maxX = max(i, maxX);
          minY = min(j, minY);
          maxY = max(j, maxY);
        }
      }
    }

    return (maxX - minX + 1) * (maxY - minY + 1);
  }
};
