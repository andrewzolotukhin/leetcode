class Solution {
public:
  long long distributeCandies(int n, int limit) {
    int k = limit < n ? limit : n;
    long long ans = 0LL;

    for (int i = 0; i <= k; i++) {
      if (n - i <= limit * 2) {
        ans += min(n - i, limit) - max(n - i - limit, 0) + 1;
      }
    }

    return ans;
  }
};
