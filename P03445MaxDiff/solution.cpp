class Solution {
private:
  int stat(int a, int b) { return ((a & 1) << 1) | (b & 1); }

public:
  int maxDifference(string s, int k) {
    int n = s.size();

    int ans = INT_MIN;

    for (auto i = '0'; i <= '4'; i++) {
      for (auto j = '0'; j <= '4'; j++) {
        if (i == j)
          continue;

        vector<int> b(4, INT_MAX);

        int ci = 0, cj = 0, pi = 0, pj = 0, l = -1;

        for (int r = 0; r < n; r++) {
          ci += (s[r] == i);
          cj += (s[r] == j);
          while (r - l >= k && cj - pj >= 2) {
            int ls = stat(pi, pj);
            b[ls] = min(b[ls], pi - pj);
            l++;
            pi += (s[l] == i);
            pj += (s[l] == j);
          }
          int rs = stat(ci, cj);
          if (b[rs ^ 0b10] != INT_MAX) {
            ans = max(ans, ci - cj - b[rs ^ 0b10]);
          }
        }
      }
    }
    return ans;
  }
};
