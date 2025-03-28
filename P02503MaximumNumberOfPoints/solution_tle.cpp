#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<pair<int, int>> directions;
  int search(vector<vector<int>> &grid, vector<vector<bool>> &visited,
             int query, set<pair<int, int>> &start, set<pair<int, int>> &next) {
    int n = grid.size();
    int m = grid[0].size();
    auto isInside = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    vector<pair<int, int>> q(start.begin(), start.end());

    int ans = 0;

    while (!q.empty()) {
      auto e = q[q.size() - 1];
      q.erase(q.end());

      if (next.count(e))
        continue;

      if (grid[e.first][e.second] >= query) {
        next.insert(e);
        continue;
      }

      if (visited[e.first][e.second])
        continue;
      visited[e.first][e.second] = true;

      // cout << "  - visited (" << e.first << ", " << e.second << ")" << endl;
      ans++;

      for (int i = 0; i < directions.size(); i++) {
        int nx = e.first + directions[i].first;
        int ny = e.second + directions[i].second;

        if (isInside(nx, ny)) {
          if (!visited[nx][ny]) {
            if (grid[nx][ny] < query) {
              q.push_back({nx, ny});
            } else {
              next.insert({nx, ny});
            }
          }
        }
      }
    }

    return ans;
  }

public:
  vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
    directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<int> ans;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    map<int, int> cache;

    vector<int> qcopy(queries.begin(), queries.end());
    sort(qcopy.begin(), qcopy.end());
    set<pair<int, int>> start;
    start.insert({0, 0});

    for (int i = 0; i < qcopy.size(); i++) {
      // cout << "Query: " << qcopy[i] << endl;
      if (i > 0 && qcopy[i - 1] == qcopy[i])
        continue;
      int q = qcopy[i];
      int r;

      set<pair<int, int>> newNext;
      r = search(grid, visited, q, start, newNext);
      start = newNext;
      cache[q] = r + ((i == 0) ? 0 : cache[qcopy[i - 1]]);
    }

    for (auto q : queries) {
      ans.push_back(cache[q]);
    }

    return ans;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;

  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  int k;
  cin >> k;
  vector<int> queries(k);
  for (auto &q : queries) {
    cin >> q;
  }

  auto result = Solution().maxPoints(grid, queries);

  for (auto &r : result) {
    cout << r << '\n';
  }
}
