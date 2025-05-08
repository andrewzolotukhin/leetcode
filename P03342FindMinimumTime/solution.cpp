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

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, int(1e9) + int(1e8)));
    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      auto len = t[0];
      auto x = t[1];
      auto y = t[2];

      if (visited[x][y])
        continue;
      visited[x][y] = true;
      if (x == n - 1 && y == m - 1) {
        break;
      }

      for (int i = 0; i < dirs.size(); i++) {
        int nx = x + dirs[i].first;
        int ny = y + dirs[i].second;

        if (isInside(nx, ny) && !visited[nx][ny]) {
          int d = max(moveTime[nx][ny], dist[x][y]) + (x + y) % 2 + 1;
          if (dist[nx][ny] > d) {
            dist[nx][ny] = d;
            pq.push({d, nx, ny});
          }
        }
      }
    }
    return dist[n - 1][m - 1];
  }
};
