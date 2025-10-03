class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> ans;

    int rem = 0;
    int len = 1;
    int d = 0;
    int r = rStart, c = cStart;

    ans.push_back({r, c});

    while (ans.size() < rows * cols) {

      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < len; j++) {
          r += dirs[d][0];
          c += dirs[d][1];
          if (r >= 0 && r < rows && c >= 0 && c < cols) {
            ans.push_back({r, c});
            if (ans.size() == rows * cols)
              return ans;
          }
        }
        d = (d + 1) % 4;
      }
      len++;
    }

    return ans;
  }
};
