#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int dist[200][200];

    int N = grid.size();
    int M = grid[0].size();

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        dist[i][j] = INT_MAX;
      }
    }

    vector<pair<pair<int, int>, int>> queue;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}};

    queue.push_back({{0, 0}, grid[0][0]});

    auto isInside = [&](int x, int y) {
      return x >= 0 && x < N && y >= 0 && y < M;
    };

    while (!queue.empty()) {
      auto item = queue[0];
      queue.erase(queue.begin());

      auto d = dist[item.first.first][item.first.second];

      if (item.second >= d) {
        continue;
      }

      dist[item.first.first][item.first.second] = item.second;

      if (item.first.first == N - 1 && item.first.second == M - 1) {
        continue;
      }

      for (int i = 0; i < directions.size(); i++) {
        auto dir = directions[i];
        auto newX = item.first.first + dir.first;
        auto newY = item.first.second + dir.second;

        if (!isInside(newX, newY)) {
          continue;
        }

        queue.push_back({{newX, newY}, item.second + grid[newX][newY]});
      }
    }

    return dist[N - 1][M - 1];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> v;

  for (int i = 0; i < n; i++) {
    vector<int> r;
    for (int j = 0; j < m; j++) {
      int k;
      cin >> k;
      r.push_back(k);
    }

    v.push_back(r);
  }

  Solution s;

  cout << s.minPathSum(v) << '\n';
}
