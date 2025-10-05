class Solution {
private:
  vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  void solve(int x, int y, vector<vector<int>> &heights,
             vector<vector<bool>> &visited) {
    int n = heights.size(), m = heights[0].size();

    if (visited[x][y])
      return;
    visited[x][y] = true;

    for (int i = 0; i < dirs.size(); i++) {
      int nx = x + dirs[i].first;
      int ny = y + dirs[i].second;

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] &&
          heights[nx][ny] >= heights[x][y]) {
        solve(nx, ny, heights, visited);
      }
    }
  }

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int n = heights.size(), m = heights[0].size();

    vector<vector<int>> ans;

    vector<vector<bool>> visitedPacific(n, vector<bool>(m, false)),
        visitedAtlantic(n, vector<bool>(m, false));

    for (int i = 0; i < m; i++) {
      solve(0, i, heights, visitedPacific);
      solve(n - 1, i, heights, visitedAtlantic);
    }

    for (int i = 0; i < n; i++) {
      solve(i, 0, heights, visitedPacific);
      solve(i, m - 1, heights, visitedAtlantic);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (visitedPacific[i][j] && visitedAtlantic[i][j]) {
          ans.push_back({i, j});
        }
      }
    }
    return ans;
  }
};
