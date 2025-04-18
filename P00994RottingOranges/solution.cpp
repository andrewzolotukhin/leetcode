class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    auto comp = [&](pair<int, pair<int, int>> &a,
                    pair<int, pair<int, int>> &b) { return a.first > b.first; };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   decltype(comp)>
        q(comp);
    int totalFresh = 0;
    auto isInside = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          for (int k = 0; k < dirs.size(); k++) {
            int dx = dirs[k].first;
            int dy = dirs[k].second;
            if (isInside(i + dx, j + dy) && grid[i + dx][j + dy] == 1) {
              q.push({1, {i + dx, j + dy}});
            }
          }
        }
        if (grid[i][j] == 1) {
          totalFresh++;
        }
      }

    if (totalFresh == 0)
      return 0;

    int ans = 0;
    int days = -1;

    while (totalFresh > 0 && !q.empty()) {
      auto curr = q.top();
      q.pop();

      int day = curr.first;
      int x = curr.second.first;
      int y = curr.second.second;

      if (grid[x][y] != 1)
        continue;

      // cout << day << ' ' << x << ' ' << y << '\n';

      days = max(days, day);

      /*
          211
          111
          012

      */

      grid[x][y] = 2;
      totalFresh--;

      for (int i = 0; i < dirs.size(); i++) {
        int nx = x + dirs[i].first;
        int ny = y + dirs[i].second;
        if (isInside(nx, ny) && grid[nx][ny] == 1) {
          q.push({day + 1, {nx, ny}});
        }
      }
    }

    return (totalFresh > 0) ? -1 : days;
  }
};
