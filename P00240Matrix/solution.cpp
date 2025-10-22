class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
      auto r = upper_bound(matrix[i].begin(), matrix[i].end(), target);
      int idx = (r == matrix[i].begin() ? -1 : (r - matrix[i].begin() - 1));
      if (idx >= 0 && matrix[i][idx] == target)
        return true;
    }
    return false;
  }
};
