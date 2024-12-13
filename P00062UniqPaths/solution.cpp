#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 1));

    for (int i = m - 2; i >= 0; i--)
      for (int j = n - 2; j >= 0; j--)
      {
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
      }

    return dp[0][0];
  }
};

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;

  Solution solution;

  cout << solution.uniquePaths(n, m) << '\n';
}
