class Solution {
private:
  void srt(vector<vector<int>> &mat, int startX, int startY) {
    int n = mat.size(), m = mat[0].size();

    int len = min(n - startX, m - startY);

    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        if (mat[startX + i][startY + i] > mat[startX + j][startY + j]) {
          swap(mat[startX + i][startY + i], mat[startX + j][startY + j]);
        }
      }
    }
  }

public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    for (int x = n - 1; x >= 0; x--) {
      srt(mat, x, 0);
    }
    for (int y = 1; y < m; y++) {
      srt(mat, 0, y);
    }
    return mat;
  }
};
