class Solution {
private:
  bool hasValid(vector<vector<char>> &grid, int x, int y, int balance,
                vector<vector<vector<bool>>> &memo) {
    int n = grid.size();
    int m = grid[0].size();

    if (x == n - 1 && y == m - 1) {
      return balance == 0;
    }
    if (balance < 0)
      return false;
    if (memo[x][y][balance])
      return false;

    if (x < n - 1 &&
        hasValid(grid, x + 1, y, balance + (grid[x + 1][y] == '(' ? 1 : -1),
                 memo)) {
      return true;
    }
    if (y < m - 1 &&
        hasValid(grid, x, y + 1, balance + (grid[x][y + 1] == '(' ? 1 : -1),
                 memo)) {
      return true;
    }
    memo[x][y][balance] = true;
    return false;
  }

public:
  bool hasValidPath(vector<vector<char>> &grid) {
    vector<vector<vector<bool>>> memo(
        110, vector<vector<bool>>(110, vector<bool>(110, false)));
    return hasValid(grid, 0, 0, (grid[0][0] == '(' ? 1 : -1), memo);
  }
};
