#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    if (n == 1 && m == 1)
      return (obstacleGrid[0][0] == 1) ? 0 : 1;

    if (obstacleGrid[n - 1][m - 1] == 1)
      return 0;

    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(m, 1));

    for (int i = n - 2; i >= 0; i--) {
      dp[i][m - 1] = (obstacleGrid[i][m - 1] != 0) ? 0 : dp[i + 1][m - 1];
    }

    for (int i = m - 2; i >= 0; i--) {
      dp[n - 1][i] = (obstacleGrid[n - 1][i] != 0) ? 0 : dp[n - 1][i + 1];
    }

    for (int i = n - 2; i >= 0; i--) {
      for (int j = m - 2; j >= 0; j--) {
        if (obstacleGrid[i][j]) {
          continue;
        } else {
          dp[i][j] = ((obstacleGrid[i + 1][j] != 0) ? 0 : dp[i + 1][j]) +
                     ((obstacleGrid[i][j + 1] != 0) ? 0 : dp[i][j + 1]);
        }
      }
    }

    return (obstacleGrid[0][0] == 1) ? 0 : dp[0][0];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  vector<vector<int>> inp;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < m; j++) {
      int t;
      cin >> t;
      row.push_back(t);
    }
    inp.push_back(row);
  }

  Solution s;

  cout << s.uniquePathsWithObstacles(inp) << '\n';
}
