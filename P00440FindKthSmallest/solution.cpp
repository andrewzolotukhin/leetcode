class Solution {
private:
  int getChildrenCount(int n, long num, long next) {
    int ans = 0;
    while (num <= n) {
      ans += min((long)(n + 1), next) - num;
      num *= 10;
      next *= 10;
    }
    return ans;
  }

public:
  int findKthNumber(int n, int k) {
    k--;
    int remaining = k;
    int num = 1;

    while (remaining > 0) {
      int children = getChildrenCount(n, num, num + 1);
      if (children <= remaining) {
        remaining -= children;
        num++;
      } else {
        num *= 10;
        remaining--;
      }
    }

    return num;
  }
};
