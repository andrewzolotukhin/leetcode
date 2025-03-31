#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  bool check(vector<vector<char>> &board, vector<vector<bool>> &visited, int x,
             int y, int k, string &word) {
    int n = board.size();
    int m = board[0].size();
    auto isInside = [&](int a, int b) {
      return a >= 0 && a < n && b >= 0 && b < m;
    };
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    if (k == word.size() - 1) {
      return true;
    }

    visited[x][y] = true;

    for (int i = 0; i < dirs.size(); i++) {
      int nx = x + dirs[i].first;
      int ny = y + dirs[i].second;

      if (isInside(nx, ny) && !visited[nx][ny] &&
          board[nx][ny] == word[k + 1]) {
        if (check(board, visited, nx, ny, k + 1, word)) {
          visited[x][y] = false;
          return true;
        }
      }
    }

    visited[x][y] = false;
    return false;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        if (board[i][j] == word[0]) {
          if (check(board, visited, i, j, 0, word)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main() {
  int n;
  cin >> n;
  vector<string> board(n);
  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  int m = board[0].size();
  vector<vector<char>> boardc(n, vector<char>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      boardc[i][j] = board[i][j];
    }
  }

  string word;
  cin >> word;

  cout << (Solution().exist(boardc, word) ? "YES" : "NO");
}
