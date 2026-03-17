class Solution {
public:
  int largestSubmatrix(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> bars(m, 0);
    int ans = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0)
          bars[j] = 0;
        else
          bars[j] += 1;
      }

      vector<int> sorted = bars;
      sort(sorted.begin(), sorted.end());

      for (int j = 0; j < m; j++) {
        ans = max(ans, sorted[j] * (m - j));
      }
    }

    return ans;
  }
};
