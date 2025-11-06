class Solution {
public:
  int countSubmatrices(vector<vector<int>> &grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<long long>> prefix(n + 1, vector<long long>(m + 1, 0));

    int ans = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                       prefix[i - 1][j - 1] + grid[i - 1][j - 1];

        if (prefix[i][j] <= k)
          ans++;
      }
    }

    return ans;
  }
};
