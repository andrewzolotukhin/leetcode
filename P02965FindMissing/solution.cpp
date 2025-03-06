class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> cnt(n * (n + 1), 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cnt[grid[i][j]]++;
      }
    }

    int f = 0, s = 0;
    for (int i = 0; i < n; i++) {
      if (f != 0)
        break;
      for (int j = 0; j < n; j++) {
        if (cnt[grid[i][j]] == 2) {
          f = grid[i][j];
        }
      }
    }

    for (int i = 1; i <= n * n; i++) {
      if (cnt[i] == 0) {
        s = i;
        break;
      }
    }

    return {f, s};
  }
};
