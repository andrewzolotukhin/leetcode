class Solution {
public:
  int countBattleships(vector<vector<char>> &board) {
    int ans = 0;
    int m = board.size(), n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == '.')
          continue;
        if (j > 0 && i > 0) {
          if ((board[i][j - 1] == '.' && board[i - 1][j] == '.')) {
            ans++;
          }
        } else if (j > 0 && i == 0) {
          if (board[i][j - 1] == '.') {
            ans++;
          }
        } else if (i > 0 && j == 0) {
          if (board[i - 1][j] == '.') {
            ans++;
          }
        } else if (i == 0 && j == 0) {
          ans++;
        }
      }
    }
    return ans;
  }
};
