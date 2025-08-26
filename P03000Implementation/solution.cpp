class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
    int maxDiag = -1000;
    int maxArea = -1000;
    for (auto r : dimensions) {
      int diag = r[0] * r[0] + r[1] * r[1];
      int area = r[0] * r[1];
      if (diag > maxDiag) {
        maxArea = area;
        maxDiag = diag;
      } else if (diag == maxDiag) {
        if (area > maxArea) {
          maxArea = area;
        }
      }
    }

    return maxArea;
  }
};
