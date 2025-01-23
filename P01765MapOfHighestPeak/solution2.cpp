#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
    int current = 1;
    int n = isWater.size();
    int m = isWater[0].size();
    vector<vector<int>> result(n, vector<int>(m, -1));

    vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (isWater[i][j] == 1) {
          result[i][j] = 0;
          pq.push({0, i, j});
        }
      }
    }

    while (!pq.empty()) {
      auto v = pq.top();
      pq.pop();
      auto height = v[0];
      auto i = v[1];
      auto j = v[2];

      for (auto &[di, dj] : directions) {
        int ni = i + di;
        int nj = j + dj;

        if (ni >= 0 && ni < n && nj >= 0 && nj < m && result[ni][nj] == -1) {
          result[ni][nj] = height + 1;
          pq.push({height + 1, ni, nj});
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

  vector<vector<int>> isWater(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> isWater[i][j];
    }
  }

  Solution solution;

  auto result = solution.highestPeak(isWater);

  for (auto &row : result) {
    for (auto &cell : row) {
      cout << cell << " ";
    }
    cout << endl;
  }
}
