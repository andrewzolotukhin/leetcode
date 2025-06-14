class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    int mod = int(1e6) + 7;
    unordered_map<int, int> cols, rows;
    int n = grid.size();

    for (int i = 0; i < n; i++) {
      cols[i] = 1;
      rows[i] = 1;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cols[j] = (1007 * cols[j] + grid[i][j]) % mod;
        rows[i] = (1007 * rows[i] + grid[i][j]) % mod;
      }
    }

    unordered_map<int, int> dR, dC;
    for (auto [k, v] : cols)
      dC[v]++;
    for (auto [k, v] : rows)
      dR[v]++;

    int ans = 0;

    for (auto [k, v] : dC) {
      if (dR.count(k)) {
        ans += dR[k] * v;
      }
    }

    return ans;
  }
};
