class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    int mod = (long long)(1e12) + 7, n = matrix.size(), m = matrix[0].size();

    vector<long long> hashes(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        hashes[i] =
            ((hashes[i] << 1) | ((matrix[i][0] == matrix[i][j]) ? 1LL : 0LL)) %
            mod;
      }
    }

    sort(hashes.begin(), hashes.end());
    int ans = 1;
    int curr = 1;
    for (int i = 1; i < hashes.size(); i++) {
      if (hashes[i] == hashes[i - 1]) {
        curr++;
      } else {
        ans = max(ans, curr);
        curr = 1;
      }
    }
    ans = max(ans, curr);
    return ans;
  }
};
