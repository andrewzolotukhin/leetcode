class Solution {
public:
  int minimumLines(vector<vector<int>> &stockPrices) {
    sort(stockPrices.begin(), stockPrices.end());
    int n = stockPrices.size();
    if (n == 1)
      return 0;
    if (n == 2)
      return 1;
    int ans = 1;
    long long dx = (long long)stockPrices[1][0] - (long long)stockPrices[0][0];
    long long dy = (long long)stockPrices[1][1] - (long long)stockPrices[0][1];
    for (int i = 2; i < n; i++) {
      long long nx =
          (long long)stockPrices[i][0] - (long long)stockPrices[i - 1][0];
      long long ny =
          (long long)stockPrices[i][1] - (long long)stockPrices[i - 1][1];
      if (dy * nx != ny * dx) {
        ans++;
        dx = nx;
        dy = ny;
      }
    }

    return ans;
  }
};
