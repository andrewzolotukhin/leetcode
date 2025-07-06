class Solution {
public:
  int arrangeCoins(int n) {
    long l = 1, r = n;
    long ans = INT_MAX;
    while (l <= r) {
      long mid = l + (r - l) / 2;
      long cnt = ((1 + mid) * mid) / 2;

      if (cnt <= n) {
        l = mid + 1;
        ans = mid;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }
};
