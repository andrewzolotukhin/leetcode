#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {

    int N = grid.size();
    int M = grid[0].size();

    vector<vector<int>> dp = vector<vector<int>>(N, vector<int>(M, INT_MAX));

    dp[0][0] = grid[0][0];

    for (int i = 1; i < N; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < M; i++) {
      dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < N; i++) {
      for (int j = 1; j < M; j++) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[N - 1][M - 1];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> v;

  for (int i = 0; i < n; i++) {
    vector<int> r;
    for (int j = 0; j < m; j++) {
      int k;
      cin >> k;
      r.push_back(k);
    }

    v.push_back(r);
  }

  Solution s;

  cout << s.minPathSum(v) << '\n';
}
