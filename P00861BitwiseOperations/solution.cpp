class Solution {
public:
  int matrixScore(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();

    vector<int> vals;

    for (int i = 0; i < n; i++) {
      int v = 0;
      for (int j = 0; j < m; j++) {
        v <<= 1;
        v |= grid[i][j];
      }
      vals.push_back(v);
    }

    int mv = 1 << (m - 1);
    int ans = n * (1 << (m - 1));

    for (int i = 0; i < n; i++) {
      if (vals[i] & mv)
        continue;
      vals[i] = ~vals[i];
    }
    mv /= 2;
    while (mv) {
      int cz = 0;
      for (int i = 0; i < n; i++) {
        if (vals[i] & mv)
          continue;
        cz++;
      }

      ans += mv * max(cz, n - cz);
      mv /= 2;
    }

    return ans;
  }
};
