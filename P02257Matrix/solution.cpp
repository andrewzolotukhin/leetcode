
class Solution {
public:
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    vector<vector<int>> map(m, vector<int>(n, 0));
    const int GUARD = 1000000;
    const int WALL = 1000001;
    for (auto &g : guards)
      map[g[0]][g[1]] = GUARD;
    for (auto &g : walls)
      map[g[0]][g[1]] = WALL;

    for (int i = 0; i < n; i++) {
      int guards = 0;
      for (int j = 0; j < m; j++) {
        if (map[j][i] == GUARD) {
          guards++;
          continue;
        }
        if (map[j][i] == WALL) {
          guards = 0;
          continue;
        }
        if (guards) {
          map[j][i]++;
        }
      }
      guards = 0;
      for (int j = m - 1; j >= 0; j--) {
        if (map[j][i] == GUARD) {
          guards++;
          continue;
        }
        if (map[j][i] == WALL) {
          guards = 0;
          continue;
        }
        if (guards) {
          map[j][i]++;
        }
      }
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
      int guards = 0;
      for (int j = 0; j < n; j++) {
        if (map[i][j] == GUARD) {
          guards++;
          continue;
        }
        if (map[i][j] == WALL) {
          guards = 0;
          continue;
        }
        if (guards) {
          map[i][j]++;
        }
      }
      guards = 0;
      for (int j = n - 1; j >= 0; j--) {
        if (map[i][j] == GUARD) {
          guards++;
          continue;
        }
        if (map[i][j] == WALL) {
          guards = 0;
          continue;
        }
        if (guards) {
          map[i][j]++;
        }
        if (map[i][j] == 0)
          ans++;
      }
    }

    return ans;
  }
};
