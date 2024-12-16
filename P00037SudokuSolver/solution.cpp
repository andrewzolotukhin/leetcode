#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(vector<vector<char>> &board, int x, int y, char value) {
    int cellX = x - x % 3;
    int cellY = y - y % 3;
    for (int i = 0; i < 9; i++) {
      if (board[i][y] == value || board[x][i] == value ||
          board[cellX + i / 3][cellY + i % 3] == value) {
        return false;
      }
    }
    return true;
  }

  bool solve2(vector<vector<char>> &board, int x, int y) {
    if (x == 9) {
      return true;
    }
    if (y == 9) {
      return solve2(board, x + 1, 0);
    }

    if (board[x][y] != '.') {
      return solve2(board, x, y + 1);
    }

    for (char value = '1'; value <= '9'; value++) {
      if (isValid(board, x, y, value)) {
        board[x][y] = value;
        if (solve2(board, x, y + 1)) {
          return true;
        }
        board[x][y] = '.';
      }
    }

    return false;
  }

  void solveSudoku(vector<vector<char>> &board) { solve2(board, 0, 0); }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  vector<vector<char>> board;

  for (int i = 0; i < 9; i++) {
    vector<char> row;
    for (int j = 0; j < 9; j++) {
      char c;
      cin >> c;
      row.push_back(c);
    }
    board.push_back(row);
  }

  Solution solution;

  solution.solveSudoku(board);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
}
