#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long gridGame(vector<vector<int>> &grid) {
    int n = grid[0].size();
    long long sum1 = 0LL;
    long long sum2 = 0LL;

    for (int i = 0; i < n; i++) {
      sum1 += grid[0][i];
    }

    long long result = LONG_LONG_MAX;

    for (int i = 0; i < n; i++) {
      sum1 -= grid[0][i];
      result = min(result, max(sum1, sum2));
      sum2 += grid[1][i];
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;

  vector<vector<int>> grid(2, vector<int>(n));

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  Solution solution;

  cout << solution.gridGame(grid) << endl;
}
