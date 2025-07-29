class Solution {
public:
  long long minCuttingCost(int n, int m, int k) {
    if (n <= k && m <= k)
      return 0LL;
    long long ans = 0;
    if (n > k) {
      if (n == 2 * k) {
        ans += (long long)k * (long long)k;
      } else {
        ans += (long long)k * (n % k);
      }
    }

    if (m > k) {
      if (m == 2 * k) {
        ans += (long long)k * (long long)k;
      } else {
        ans += (long long)k * (m % k);
      }
    }

    return ans;
  }
};
