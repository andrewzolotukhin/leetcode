class Solution {
private:
public:
  int minFlips(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int midN = n / 2 + (n % 2);
    int midM = m / 2 + (m % 2);

    int ans = 0;
    for (int i = midN; i < n; i++) {
      for (int j = midM; j < m; j++) {
        int ones = grid[i][j] + grid[i][m - j - 1] + grid[n - 1 - i][j] +
                   grid[n - i - 1][m - 1 - j];
        ans += min(4 - ones, ones);
      }
    }

    int middle = 0, sum = 0;
    if (n & 1) {
      for (int j = midM; j < m; j++) {
        int s = grid[n / 2][j] + grid[n / 2][m - j - 1];
        middle += min(s, 2 - s);
        sum += s;
      }
    }

    if (m & 1) {
      for (int j = midN; j < n; j++) {
        int s = grid[j][m / 2] + grid[n - j - 1][m / 2];
        middle += min(s, 2 - s);
        sum += s;
      }
    }

    if (middle < 2 && sum % 4) {
      ans += min(sum % 4, 4 - sum % 4);
    } else {
      ans += middle;
    }

    ans += ((n & 1) && (m & 1) && grid[n / 2][m / 2]);

    return ans;
  }
};
