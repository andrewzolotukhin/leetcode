class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    // 0 1 0
    // 0 0 1
    // 1 1 1
    // 0 0 0

    // -1   1 -2
    // -3  -4  3
    //  1   3  2
    // -2  -3 -2

    // 0 0 0
    // 1 0 1
    // 0 1 1
    // 0 1 0

    int n = board.size();
    int m = board[0].size();
    auto isInside = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0)
              continue;
            if (isInside(i + dx, j + dy)) {
              if (board[i + dx][j + dy] > 0) {
                if (board[i][j] <= 0) {
                  board[i][j]--;
                } else {
                  board[i][j]++;
                }
              }
            }
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] <= 0) {
          board[i][j] = board[i][j] == -3 ? 1 : 0;
        } else {
          if (board[i][j] < 3) {
            board[i][j] = 0;
          } else if (board[i][j] > 4) {
            board[i][j] = 0;
          } else {
            board[i][j] = 1;
          }
        }
      }
    }
  }
};
