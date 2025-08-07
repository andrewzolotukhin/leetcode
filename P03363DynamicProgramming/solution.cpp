class Solution {
public:
  int maxCollectedFruits(vector<vector<int>> &fruits) {
    int n = fruits.size();
    int p2r = 0, p2c = n - 1, p3r = n - 1, p3c = 0;
    int p1s = 0, p2s = fruits[p2r][p2c], p3s = fruits[p3r][p3c];

    for (int i = 0; i < n; i++) {
      p1s += fruits[i][i];
      fruits[i][i] = 0;
    }
    int ans = 0;
    auto solve = [&]() {
      vector<int> p(n, INT_MIN), c(n, INT_MIN);
      p[n - 1] = fruits[0][n - 1];
      for (int i = 1; i < n - 1; i++) {
        for (int j = max(n - 1 - i, i + 1); j < n; j++) {
          int b = p[j];
          if (j >= 1) {
            b = max(b, p[j - 1]);
          }
          if (j < n - 1) {
            b = max(b, p[j + 1]);
          }
          c[j] = b + fruits[i][j];
        }
        swap(p, c);
      }
      return p[n - 1];
    };

    ans += solve();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        swap(fruits[i][j], fruits[j][i]);
      }
    }

    ans += solve();

    return p1s + ans;
  }
};
