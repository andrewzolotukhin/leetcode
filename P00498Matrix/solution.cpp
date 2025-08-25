class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    vector<int> ans;

    if (mat.size() == 0)
      return ans;

    int n = mat.size();
    int m = mat[0].size();

    int r = 0, c = 0;

    int dir = 1;

    while (r < n && c < m) {
      ans.push_back(mat[r][c]);
      int nr = r + (dir == 1 ? -1 : 1);
      int nc = c + (dir == 1 ? 1 : -1);

      if (nr < 0 || nr == n || nc < 0 || nc == m) {
        if (dir == 1) {
          r += (c == m - 1) ? 1 : 0;
          c += (c < m - 1) ? 1 : 0;
        } else {
          c += (r == n - 1) ? 1 : 0;
          r += (r < n - 1) ? 1 : 0;
        }
        dir = 1 - dir;
      } else {
        r = nr;
        c = nc;
      }
    }

    return ans;
  }
};
