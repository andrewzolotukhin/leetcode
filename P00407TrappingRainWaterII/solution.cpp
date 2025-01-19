#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n = heightMap.size(), m = heightMap[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
    vector<vector<bool>> v(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
      v[i][0] = true;
      v[i][m - 1] = true;
      q.push({heightMap[i][0], i, 0});
      q.push({heightMap[i][m - 1], i, m - 1});
    }
    for (int i = 0; i < m; i++) {
      v[0][i] = true;
      v[n - 1][i] = true;
      q.push({heightMap[0][i], 0, i});
      q.push({heightMap[n - 1][i], n - 1, i});
    }
    int r = 0;
    while (!q.empty()) {
      auto c = q.top();
      q.pop();
      int ch = c[0], cr = c[1], cc = c[2];
      for (int i = 0; i < dirs.size(); i++) {
        int nc = cc + dirs[i].first;
        int nr = cr + dirs[i].second;
        if (nc < 0 || nc >= m || nr < 0 || nr >= n || v[nr][nc])
          continue;
        if (heightMap[nr][nc] < ch) {
          r += ch - heightMap[nr][nc];
        }
        q.push({max(ch, heightMap[nr][nc]), nr, nc});
        v[nr][nc] = true;
      }
    }
    return r;
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> h(n, vector<int>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      h[i].push_back(x);
    }
  }
  Solution s;
  cout << s.trapRainWater(h) << '\n';
  return 0;
}
