class Solution {
public:
  bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
    bool e1 = true, e2 = true, e3 = true, e4 = true;
    int n = mat.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        e1 = e1 && (target[i][j] == mat[i][j]);
        e2 = e2 && (target[i][j] == mat[n - 1 - j][i]);
        e3 = e3 && (target[i][j] == mat[j][n - 1 - i]);
        e4 = e4 && (target[i][j] == mat[n - 1 - i][n - 1 - j]);
      }
    }
    return e1 || e2 || e3 || e4;
  }
};
