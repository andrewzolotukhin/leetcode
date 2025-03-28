#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<int> ans;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    set<int> diffQueries;

    for (int i = 0; i < queries.size(); i++) {
      diffQueries.insert(queries[i]);
    }

    vector<int> ansOrdered(diffQueries.begin(), diffQueries.end());

    int k = 0;

    auto compare = [&](vector<int> &a, vector<int> &b) { return a[0] > b[0]; };

    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> q(
        compare);
    q.push({grid[0][0], 0, 0});

    map<int, int> cache;
    int total = 0;
    int target = ansOrdered[k];

    while (!q.empty()) {
      auto e = q.top();
      q.pop();

      int v = e[0];
      int x = e[1];
      int y = e[2];

      // cout << "Now in " << x << " " << y << " with value " << v << endl;

      if (visited[x][y])
        continue;

      if (v >= target) {
        while (k < ansOrdered.size() && v >= ansOrdered[k]) {
          cache[ansOrdered[k]] = total;
          k++;
        }
        if (k >= ansOrdered.size()) {
          break;
        }
        target = ansOrdered[k];
        // cout << "New target is " << target << endl;
      }

      visited[x][y] = true;
      // cout << "Visiting " << x << " " << y << " with value " << v << endl;
      total++;
      cache[target] = total;

      for (int i = 0; i < directions.size(); i++) {
        int nx = x + directions[i].first;
        int ny = y + directions[i].second;

        if (!(nx >= 0 && nx < n && ny >= 0 && ny < m)) {
          continue;
        }

        if (visited[nx][ny]) {
          continue;
        }

        // cout << "Adding neighbor " << nx << " " << ny << " with value "
        // << grid[nx][ny] << endl;
        q.push({grid[nx][ny], nx, ny});
      }
    }

    while (k < ansOrdered.size()) {
      cache[ansOrdered[k]] = total;
      k++;
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
