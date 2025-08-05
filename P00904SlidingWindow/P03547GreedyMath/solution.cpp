class Solution {

public:
  long long maxScore(int n, vector<vector<int>> &edges) {
    long long x = (n - 1) / 2;
    long long y = n / 2 - 1;

    long long odd = x * (x + 1) * (2 * x + 1) / 3 * 2 - x;
    long long even = y * (y + 1) * (y + 2) / 3 * 4;

    long long ans = odd + even + n * (n - 1LL);
    if (edges.size() == n) {
      ans += 2;
    }

    return ans;
  }
};
