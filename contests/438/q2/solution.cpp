class Solution {
public:
  long long maxSum(vector<vector<int>> &grid, vector<int> &limits, int k) {
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
      sort(grid[i].begin(), grid[i].end(), greater<int>());
    }

    priority_queue<int> queue;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < min(k, limits[i]); j++) {
        queue.push(grid[i][j]);
      }
    }

    long long result = 0LL;
    int left = k;

    while (!queue.empty() && left > 0) {
      result += queue.top();
      queue.pop();
      left--;
    }

    return result;
  }
};
