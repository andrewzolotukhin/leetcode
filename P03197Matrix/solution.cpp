class Solution {
public:
  int getRectArea(vector<vector<int>> &grid, int startR, int endR, int startC,
                  int endC) {
    int minR = grid.size(), maxR = 0;
    int minC = grid[0].size(), maxC = 0;
    for (int i = startR; i <= endR; i++) {
      for (int j = startC; j <= endC; j++) {
        if (grid[i][j] == 1) {
          minR = min(minR, i);
          maxR = max(maxR, i);
          minC = min(minC, j);
          maxC = max(maxC, j);
        }
      }
    }

    return minR <= maxR ? (maxR - minR + 1) * (maxC - minC + 1) : INT_MAX / 3;
  }

  vector<vector<int>> rotate(vector<vector<int>> &grid) {
    int r = grid.size(), c = grid[0].size();
    vector<vector<int>> ans(c, vector<int>(r));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        ans[c - j - 1][i] = grid[i][j];
      }
    }
    return ans;
  }

  int solve(vector<vector<int>> &grid) {
    int r = grid.size(), c = grid[0].size();
    int ans = r * c;

    for (int i = 0; i < r - 1; i++) {
      for (int j = 0; j < c - 1; j++) {
        ans = min(ans, getRectArea(grid, 0, i, 0, c - 1) +
                           getRectArea(grid, i + 1, r - 1, 0, j) +
                           getRectArea(grid, i + 1, r - 1, j + 1, c - 1));
        ans = min(ans, getRectArea(grid, 0, i, 0, j) +
                           getRectArea(grid, 0, i, j + 1, c - 1) +
                           getRectArea(grid, i + 1, r - 1, 0, c - 1));
      }
    }
    for (int i = 0; i < r - 2; i++) {
      for (int j = i + 1; j < r - 1; j++) {
        ans = min(ans, getRectArea(grid, 0, i, 0, c - 1) +
                           getRectArea(grid, i + 1, j, 0, c - 1) +
                           getRectArea(grid, j + 1, r - 1, 0, c - 1));
      }
    }

    return ans;
  }

  int minimumSum(vector<vector<int>> &grid) {
    auto rotated = rotate(grid);
    return min(solve(grid), solve(rotated));
  }
};
