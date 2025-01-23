#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int countServers(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<set<pair<int, int>>> rows(n, set<pair<int, int>>()),
        cols(m, set<pair<int, int>>());

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          pair<int, int> p = {i, j};
          rows[i].insert(p);
          cols[j].insert(p);
        }
      }
    }

    int result = 0;
    vector<vector<bool>> u(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
      if (rows[i].size() > 1) {
        for (auto p : rows[i]) {
          if (!u[p.first][p.second]) {
            result++;
            u[p.first][p.second] = true;
          }
        }
      }
    }

    for (int i = 0; i < m; i++) {
      if (cols[i].size() > 1) {
        for (auto p : cols[i]) {
          if (!u[p.first][p.second]) {
            result++;
            u[p.first][p.second] = true;
          }
        }
      }
    }

    return result;
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

  Solution sol;

  cout << sol.countServers(grid) << '\n';
}
