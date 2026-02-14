class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> ans(102, vector<double>(102, 0));
    ans[0][0] = poured;

    for (int i = 0; i <= query_row; i++) {
      for (int j = 0; j <= i; j++) {
        double r = (ans[i][j] - 1.0) / 2.0;
        if (r > 0) {
          ans[i + 1][j] += r;
          ans[i + 1][j + 1] += r;
        }
      }
    }

    return min(1.0, ans[query_row][query_glass]);
  }
};
