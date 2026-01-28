class Solution {
public:
  int minCost(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> pts;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        pts.push_back({i, j});
      }
    }

    sort(pts.begin(), pts.end(), [&](auto &p1, auto &p2) {
      return grid[p1.first][p1.second] < grid[p2.first][p2.second];
    });
    vector<vector<int>> costs(m, vector<int>(n, INT_MAX));

    for (int t = 0; t <= k; t++) {
      int mc = INT_MAX;
      for (int i = 0, j = 0; i < pts.size(); i++) {
        mc = min(mc, costs[pts[i].first][pts[i].second]);
        if (i + 1 < pts.size() &&
            grid[pts[i].first][pts[i].second] ==
                grid[pts[i + 1].first][pts[i + 1].second]) {
          continue;
        }
        for (int k = j; k <= i; k++) {
          costs[pts[k].first][pts[k].second] = mc;
        }

        j = i + 1;
      }

      for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
          if (i == m - 1 && j == n - 1) {
            costs[i][j] = 0;
            continue;
          }
          if (i != m - 1) {
            costs[i][j] = min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
          }
          if (j != n - 1) {
            costs[i][j] = min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
          }
        }
      }
    }
    return costs[0][0];
  }
};
