class Solution {
public:
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    int n = maze.size();
    int m = maze[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    auto comp = [&](vector<int> &a, vector<int> &b) { return a[0] > b[0]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
    pq.push({0, entrance[0], entrance[1]});

    auto isInside = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    while (!pq.empty()) {
      auto current = pq.top();
      pq.pop();

      auto dist = current[0];
      auto x = current[1];
      auto y = current[2];

      if (visited[x][y])
        continue;
      visited[x][y] = true;

      if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
        if (x != entrance[0] || y != entrance[1]) {
          return dist;
        }
      }

      for (int i = 0; i < dirs.size(); i++) {
        int dx = dirs[i].first;
        int dy = dirs[i].second;
        int nx = dx + x;
        int ny = dy + y;

        if (isInside(nx, ny) && !visited[nx][ny] && maze[nx][ny] == '.') {
          pq.push({dist + 1, nx, ny});
        }
      }
    }

    return -1;
  }
};
