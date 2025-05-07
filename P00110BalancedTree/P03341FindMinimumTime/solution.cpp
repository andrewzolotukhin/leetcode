class Solution {
public:
  int minTimeToReach(vector<vector<int>> &moveTime) {
    auto comp = [&](vector<int> &a, vector<int> &b) { return a[0] > b[0]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n = moveTime.size();
    int m = moveTime[0].size();

    auto isInside = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    for (auto [dx, dy] : dirs) {
      if (isInside(dx, dy)) {
        pq.push({moveTime[dx][dy], dx, dy});
      }
    }

    int ans = INT_MAX;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[0][0] = true;

    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      auto len = t[0];
      auto x = t[1];
      auto y = t[2];

      if (len > ans)
        continue;

      if (visited[x][y])
        continue;
      visited[x][y] = true;
      if (x == n - 1 && y == m - 1) {
        if (len < ans)
          ans = len;
        continue;
      }

      for (int i = 0; i < dirs.size(); i++) {
        int nx = x + dirs[i].first;
        int ny = y + dirs[i].second;

        if (isInside(nx, ny) && !visited[nx][ny]) {
          int time =
              (len + 1) > moveTime[nx][ny] ? (len + 1) : moveTime[nx][ny];
          pq.push({time, nx, ny});
        }
      }
    }
    return ans + 1;
  }
};
