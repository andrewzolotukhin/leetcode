class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid) {
    int n = boxGrid.size(), m = boxGrid[0].size();
    auto ans = vector<vector<char>>(m, vector<char>(n));

    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 2; j >= 0; j--) {
        if (boxGrid[i][j] != '#')
          continue;
        int k = j;

        while (k < m - 1 && boxGrid[i][k + 1] == '.') {
          boxGrid[i][k + 1] = boxGrid[i][k];
          boxGrid[i][k] = '.';
          k++;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans[j][n - 1 - i] = boxGrid[i][j];
      }
    }

    return ans;
  }
};
